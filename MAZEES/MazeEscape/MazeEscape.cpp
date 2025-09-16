// =====================================================================================
// Maze Escape - Robust Single File (C++17)
// -------------------------------------------------------------------------------------
// ■ 목적
//   - "입력 안전화" 적용: 숫자 아닌 값, 빈 줄, 공백, CRLF/LF 등에 대해 무한루프 없이 정상 재요청
//   - 이전 문제: std::cin >> pay 에서 실패(failbit) 발생 시 버퍼가 회복되지 않아
//                동일 메시지 무한 반복 → [Fix-2], [Fix-3], [Fix-4]로 해결
//
// ■ 단계별 설계(Flow)
//   (S1) 난수 시드 설정 → (S2) InitializeMaze() [파일 읽기 → 파싱] → (S3) MazeEscapeRun()
//        → 매 틱: 맵 출력 → 도착 검사 → 이동 가능한 키 표시 → [안전 입력] 방향 선택
//        → 이동 후 MoveEventProcess(): [전투] 또는 [힐러] 또는 [없음]
//        → 종료 시 ClearMaze()
//
// ■ 맵 파일: ".\\Data\\MapData.txt"
//   - 첫 줄: "W,H"
//   - 이후 H줄: 콤마로 구분된 정수 W개 (0=길,1=벽,2=시작,3=도착)
// =====================================================================================

#define _CRT_SECURE_NO_WARNINGS
// #define TEST_MODE  // 전투만 빠르게 테스트하려면 주석 해제 해보세요

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>    // printf, snprintf
#include <cstdlib>   // rand, srand, exit
#include <ctime>     // time
#include <cctype>    // isspace, tolower
#include <algorithm> // find_if (trim)
#include <limits>    // numeric_limits
#include <climits>   // INT_MIN, INT_MAX

// ============================== 전역 상수/타입 =======================================

enum CellType : int { Path = 0, Wall = 1, Start = 2, End = 3 };

enum MoveDirection : int {
    DirNone = 0, DirUp = 1 << 0, DirDown = 1 << 1, DirLeft = 1 << 2, DirRight = 1 << 3
};

struct Position { int x = 0; int y = 0; };

struct PlayerData {
    Position CurrentPosition{};
    float Health = 100.0f, MaxHealth = 100.0f, AttackPower = 10.0f;
    int Gold = 0;
};

struct EnemyData {
    float Health = 30.0f, AttackPower = 5.0f;
    int DropGold = 20;
};

// ============================== 전역 상태(맵) =========================================

const char* DirectoryName = ".\\Data\\";
int MazeWidth = 20, MazeHeight = 10;
int** Maze = nullptr;

// ============================== 유틸: 안전한 입출력 ================================
// [Fix-1] 입력 안전화를 위한 보조 함수들 추가

// 좌우 공백 제거
static inline void Trim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end());
}

// 한 줄 안전 읽기: getline 사용 + CR 제거 + 실패 상태 복구
//  - 문자를 쳐도, 빈 줄을 쳐도, 공백만 쳐도, 스트림이 fail 상태여도 복구 시도
//  - 반환값: 성공 true, 실패(EOF 등) false
bool SafeGetLine(std::string& out) {                           // [Fix-2]
    out.clear();
    if (!std::getline(std::cin, out)) {
        // 실패 상태 복구 시도
        if (std::cin.fail() && !std::cin.eof()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        return false;
    }
    // CRLF 케이스: \r 제거
    if (!out.empty() && out.back() == '\r') out.pop_back();
    return true;
}

// "정수만" 엄격 파싱 (공백 허용, 숫자만 허용, 전체 소비)
//  - 예: "  123 " OK, "12a" NG, "+" / "-" 허용
bool ParseIntStrict(const std::string& s_in, int& out) {       // [Fix-3]
    std::string s = s_in;
    Trim(s);
    if (s.empty()) return false;
    size_t idx = 0;
    try {
        long v = std::stol(s, &idx, 10);
        if (idx != s.size()) return false; // 남은 문자 있으면 실패
        if (v < INT_MIN || v > INT_MAX) return false;
        out = static_cast<int>(v);
        return true;
    }
    catch (...) {
        return false;
    }
}

// 정수 입력을 [min..max] 범위로 안전 요청 (취소값 허용 가능)
//  - 숫자가 아니면 "숫자를 입력하세요" 재안내
//  - 범위 밖이면 "범위 안내" 재안내
int AskIntInRange(const char* prompt, int minv, int maxv) {    // [Fix-4]
    for (;;) {
        std::printf("%s", prompt);
        std::string line;
        if (!SafeGetLine(line)) {
            std::printf("입력을 다시 시도하세요.\n");
            continue;
        }
        int value = 0;
        if (!ParseIntStrict(line, value)) {
            std::printf("숫자를 입력하세요.\n");
            continue;
        }
        if (value < minv || value > maxv) {
            std::printf("허용 범위: %d ~ %d\n", minv, maxv);
            continue;
        }
        return value;
    }
}

// 방향 입력(문자) 안전 요청: 유효 키 목록에 맞는지 검사하고, 아니면 키 목록 재안내
MoveDirection AskMoveDirection(int flags) {                    // [Fix-5]
    for (;;) {
        std::printf("Input direction : ");
        std::string line;
        if (!SafeGetLine(line)) {
            std::printf("입력을 다시 시도하세요.\n");
            continue;
        }
        // 첫 비공백 문자만 사용
        char c = 0;
        for (char ch : line) { if (!std::isspace((unsigned char)ch)) { c = ch; break; } }
        if (c == 0) { std::printf("키를 입력하세요.\n"); continue; }
        c = (char)std::tolower((unsigned char)c);

        if (c == 'w' && (flags & DirUp))    return DirUp;
        if (c == 's' && (flags & DirDown))  return DirDown;
        if (c == 'a' && (flags & DirLeft))  return DirLeft;
        if (c == 'd' && (flags & DirRight)) return DirRight;

        // 유효 키 목록 재안내 (무한 같은 문구 방지: 매번 현재 유효키를 친절히 노출)
        std::printf("Wrong input. Valid keys: ");
        if (flags & DirUp)    std::printf("W ");
        if (flags & DirDown)  std::printf("S ");
        if (flags & DirLeft)  std::printf("A ");
        if (flags & DirRight) std::printf("D ");
        std::printf("\n");
    }
}

// ============================== 함수 원형(프로토타입) =================================
// (호출 전에 선언 필요)

bool ReadMapFile(const char* MapFileName, std::string& OutDataString);
bool ParseMapData(std::string& DataString);

void InitializeMaze();
void MazeEscapeRun();
void ClearMaze();

void PrintMaze(const Position& position);                 // [Fix-6] const 참조
void FindStartPosition(Position& OutPosition);
int  PrintAvailableMoves(const Position& position);       // [Fix-6] const 참조
bool IsWall(int X, int Y);
bool IsEnd(const Position& position);                     // [Fix-6] const 참조
MoveDirection GetMoveInput(int MoveFlags);

void MoveEventProcess(PlayerData& Player);
void BattleEvent(PlayerData& Player);
void HealerEvent(PlayerData& Player);

// ============================== (테스트용) 구조체 =====================================
struct Test {
    void TestBattle() {
        PlayerData player;
        player.Health = 50.0f; player.MaxHealth = 100.0f;
        player.AttackPower = 15.0f; player.Gold = 10;
        std::cout << "[TEST] BattleEvent 시작\n";
        BattleEvent(player); // [Fix-1] 위에서 원형 선언했으므로 식별자 OK
        std::cout << "[TEST] 종료. HP=" << player.Health << " / Gold=" << player.Gold << "\n";
    }
};

// ============================== 구현부: 파일/파싱 =====================================

// 파일 전체를 문자열로 읽기 (경로 결합 안전화)
bool ReadMapFile(const char* MapFileName, std::string& OutDataString) {
    char FilePath[256];
    std::snprintf(FilePath, sizeof(FilePath), "%s%s", DirectoryName, MapFileName);
    std::ifstream ifs(FilePath, std::ios::in | std::ios::binary);
    if (!ifs.is_open()) {
        std::printf("File open FAIL!\n[%s] Check file path.\n", FilePath);
        return false;
    }
    OutDataString.assign((std::istreambuf_iterator<char>(ifs)),
        std::istreambuf_iterator<char>());
    return true;
}

// 맵 문자열 파싱 (getline 기반으로 CR/LF 자동 처리)
bool ParseMapData(std::string& DataString) {
    ClearMaze(); // [Fix-7] 기존 메모리 정리(누수 방지)

    std::istringstream iss(DataString);
    std::string line;

    // 헤더: "W,H"
    if (!std::getline(iss, line)) return false;
    Trim(line);
    {
        std::istringstream ls(line);
        char comma = 0; int w = 0, h = 0;
        ls >> w >> comma >> h;
        if (!ls || comma != ',' || w <= 0 || h <= 0) {
            std::printf("Map header parse FAIL (expected: W,H)\n");
            return false;
        }
        MazeWidth = w; MazeHeight = h;
    }

    // 2차원 배열 할당
    Maze = new int* [MazeHeight];
    for (int y = 0; y < MazeHeight; ++y) Maze[y] = new int[MazeWidth] {};

    // 본문 라인: H줄 × 각 줄 W개 정수(콤마 구분)
    for (int y = 0; y < MazeHeight; ++y) {
        if (!std::getline(iss, line)) {
            std::printf("Map data lines insufficient (y=%d)\n", y);
            return false;
        }
        std::istringstream ls(line);
        for (int x = 0; x < MazeWidth; ++x) {
            int v = 0; char comma = 0;
            ls >> v;
            if (!ls) { std::printf("Map cell parse FAIL at (%d,%d)\n", x, y); return false; }
            if (x < MazeWidth - 1) {
                ls >> comma;
                if (!ls || comma != ',') { std::printf("Comma expected after cell (%d,%d)\n", x, y); return false; }
            }
            Maze[y][x] = v;
        }
    }
    return true;
}

void InitializeMaze() {
    std::string Data;
    if (!ReadMapFile("MapData.txt", Data)) {
        std::printf("Fallback: 기본 맵 생성\n");
        ClearMaze();
        MazeWidth = 10; MazeHeight = 6;
        Maze = new int* [MazeHeight];
        for (int y = 0; y < MazeHeight; ++y) {
            Maze[y] = new int[MazeWidth] {};
            for (int x = 0; x < MazeWidth; ++x) {
                bool border = (x == 0 || y == 0 || x == MazeWidth - 1 || y == MazeHeight - 1);
                Maze[y][x] = border ? Wall : Path;
            }
        }
        Maze[1][1] = Start; Maze[MazeHeight - 2][MazeWidth - 2] = End;
        return;
    }
    if (!ParseMapData(Data)) {
        std::printf("ParseMapData FAIL. 종료합니다.\n");
        std::exit(EXIT_FAILURE);
    }
}

void ClearMaze() {
    if (Maze) {
        for (int y = 0; y < MazeHeight; ++y) { delete[] Maze[y]; Maze[y] = nullptr; }
        delete[] Maze; Maze = nullptr;
    }
}

// ============================== 구현부: 게임 로직 =====================================

void PrintMaze(const Position& position) { // [Fix-6] const 참조
    for (int y = 0; y < MazeHeight; ++y) {
        for (int x = 0; x < MazeWidth; ++x) {
            if (position.x == x && position.y == y)      std::printf("P ");
            else if (Maze[y][x] == Wall)               std::printf("# ");
            else if (Maze[y][x] == Path)               std::printf(". ");
            else if (Maze[y][x] == Start)              std::printf("S ");
            else if (Maze[y][x] == End)                std::printf("E ");
            else                                     std::printf("? ");
        }
        std::printf("\n");
    }
}

void FindStartPosition(Position& OutPosition) {
    for (int y = 0; y < MazeHeight; ++y)
        for (int x = 0; x < MazeWidth; ++x)
            if (Maze[y][x] == Start) { OutPosition.x = x; OutPosition.y = y; return; }
    OutPosition = { 0,0 };
}

bool IsWall(int X, int Y) {
    if (Y < 0 || Y >= MazeHeight || X < 0 || X >= MazeWidth) return true;
    return Maze[Y][X] == Wall;
}

bool IsEnd(const Position& position) { // [Fix-6]
    return Maze[position.y][position.x] == End;
}

int PrintAvailableMoves(const Position& position) { // [Fix-6]
    int flags = DirNone;
    std::printf("Select movable direction (w:Up a:Left s:Down d:Right):\n");
    if (!IsWall(position.x, position.y - 1)) { std::printf("W(↑) "); flags |= DirUp; }
    if (!IsWall(position.x, position.y + 1)) { std::printf("S(↓) "); flags |= DirDown; }
    if (!IsWall(position.x - 1, position.y)) { std::printf("A(←) "); flags |= DirLeft; }
    if (!IsWall(position.x + 1, position.y)) { std::printf("D(→) "); flags |= DirRight; }
    std::printf("\n");
    return flags;
}

MoveDirection GetMoveInput(int MoveFlags) {
    return AskMoveDirection(MoveFlags); // [Fix-5] 안전 입력 사용
}

void MoveEventProcess(PlayerData& Player) {
    float r = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
    if (r < 0.2f) { std::printf("An enemy appeared!\n"); BattleEvent(Player); }
    else if (r < 0.4f) { std::printf("You found a Healer!\n"); HealerEvent(Player); }
    else { std::printf("Nothing happened.\n"); }
}

void BattleEvent(PlayerData& Player) {
    EnemyData Enemy;
    std::printf("Battle Start!\n");
    while (Player.Health > 0 && Enemy.Health > 0)
    {
        Enemy.Health -= Player.AttackPower;
        std::printf("Player attacks! Enemy Health: %.1f\n", Enemy.Health);
        if (Enemy.Health <= 0) {
            std::printf("Enemy defeated!\nYou gained %d gold.\n", Enemy.DropGold);
            Player.Gold += Enemy.DropGold; break;
        }
        Player.Health -= Enemy.AttackPower;
        std::printf("Enemy attacks! Player Health: %.1f\n", Player.Health);
        if (Player.Health <= 0) std::printf("Player defeated!\n");
    }
}

void HealerEvent(PlayerData& Player) {
    std::printf("Healer: How much gold will you pay for healing?\n(Current Health: %.1f, Current Gold: %d)\n",
        Player.Health, Player.Gold);

    // [Fix-4] 숫자 아닌 입력/음수/초과 모두 방어. 0 입력 시 치료 취소.
    int pay = AskIntInRange("Enter gold to pay (0 to cancel): ", 0, Player.Gold);

    if (pay == 0) {
        std::printf("Don't you want a heal? OK.\n");
    }
    else {
        float newHP = Player.Health + static_cast<float>(pay);
        if (newHP > Player.MaxHealth) newHP = Player.MaxHealth;
        Player.Health = newHP; Player.Gold -= pay;
        std::printf("Healed!\n");
    }
    std::printf("Current Health: %.1f, Remaining Gold: %d\n", Player.Health, Player.Gold);
}

void MazeEscapeRun() {
    PlayerData Player;
    FindStartPosition(Player.CurrentPosition);
    std::printf("~~ Maze Escape ~~\n");

    while (Player.Health > 0)
    {
        PrintMaze(Player.CurrentPosition);
        if (IsEnd(Player.CurrentPosition)) { std::printf("Congratulations! You have escaped the maze!\n"); break; }

        int flags = PrintAvailableMoves(Player.CurrentPosition);
        MoveDirection dir = GetMoveInput(flags);
        if (dir == DirUp)    --Player.CurrentPosition.y;
        if (dir == DirDown)  ++Player.CurrentPosition.y;
        if (dir == DirLeft)  --Player.CurrentPosition.x;
        if (dir == DirRight) ++Player.CurrentPosition.x;

        MoveEventProcess(Player);
    }
    if (Player.Health <= 0) std::printf("Game Over.\n");
}

// ================================= main ==============================================

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // 난수 시드
#ifdef TEST_MODE
    Test t; t.TestBattle();
#else
    InitializeMaze();
    MazeEscapeRun();
    ClearMaze();
#endif
    return 0;
}
