#define _CRT_SECURE_NO_WARNINGS
#include "0912practice.h"
#include <cstdio>
#include <random>
#include <ctime>
#include <algorithm>

// RNG & 밸런스
static std::mt19937 rng{ static_cast<unsigned>(std::time(nullptr)) };
static constexpr int kBattlePct = 20;
static constexpr int kHealPct = 10;
static constexpr int kMaxHeal = 20;

static constexpr int kPlMin = 8, kPlMax = 18;
static constexpr int kEHmin = 30, kEHmax = 80;
static constexpr int kEAmin = 5, kEAmax = 15;
static constexpr int kEGmin = 20, kEGmax = 60;

// Position 테스트
void LocationDetect() {
    Position p1(10, 20), p2(5, 15);
    Position sum = p1 + p2;
    Position diff = p1 - p2;
    std::printf("sum = (%d + %d, %d + %d) = (%d, %d)\n", p1.x, p2.x, p1.y, p2.y, sum.x, sum.y);
    std::printf("diff = (%d - %d, %d - %d) = (%d, %d)\n", p1.x, p2.x, p1.y, p2.y, diff.x, diff.y);
}

// 유틸
static Enemy SpawnEnemy() {
    std::uniform_int_distribution<int> hp(kEHmin, kEHmax);
    std::uniform_int_distribution<int> atk(kEAmin, kEAmax);
    std::uniform_int_distribution<int> g(kEGmin, kEGmax);
    return Enemy("Goblin", hp(rng), atk(rng), g(rng));
}

static void ResolveBattle(Player& p, Enemy& e) {
    std::uniform_int_distribution<int> pdmg(kPlMin, kPlMax);
    std::printf("[전투] %s HP=%d Atk=%d Gold=%d\n",
        e.Name.c_str(), e.HP, e.Atk, e.DropGold);

    while (p.HP > 0 && e.HP > 0) {
        e.HP -= pdmg(rng);
        if (e.HP <= 0) break;
        p.HP -= e.Atk;
    }
    if (p.HP > 0) {
        p.Gold += e.DropGold;
        std::printf("적 격파! +%dG\n", e.DropGold);
    }
    else {
        std::printf("플레이어가 쓰러졌습니다...\n");
    }
}

static void HealByGold(Player& p) {
    if (p.HP >= p.MaxHP) { std::printf("[회복] 이미 풀피\n"); return; }
    int need = p.MaxHP - p.HP;
    int pay = std::min(need, std::min(p.Gold, kMaxHeal));
    if (pay <= 0) { std::printf("[회복] Gold 부족\n"); return; }
    p.Gold -= pay; p.HP += pay;
    std::printf("[회복] -%dG +%dHP (HP=%d/%d, Gold=%d)\n", pay, pay, p.HP, p.MaxHP, p.Gold);
}

static void StepEvent(Player& p) {
    std::uniform_int_distribution<int> d(0, 99);
    int r = d(rng);
    if (r < kBattlePct) {
        Enemy e = SpawnEnemy();
        ResolveBattle(p, e);
    }
    else if (r < kBattlePct + kHealPct) {
        HealByGold(p);
    }
}

// 엔트리(9/9 루프 재사용)
void Day0912_AdvancedMaze() {
    Player pl;
    FindStartPosition(pl.x, pl.y);

    std::printf("~~ 미로 탈출(9/12) ~~\n");
    while (true) {
        PrintMaze(pl.x, pl.y);
        std::printf("HP:%d/%d | Gold:%d\n", pl.HP, pl.MaxHP, pl.Gold);

        if (IsEnd(pl.x, pl.y)) { std::printf("클리어!\n"); break; }

        int flags = PrintAvailableMoves(pl.x, pl.y);
        MoveDirection dir = GetMoveInput(flags);
        switch (dir) {
        case DirUp:    --pl.y; break;
        case DirDown:  ++pl.y; break;
        case DirLeft:  --pl.x; break;
        case DirRight: ++pl.x; break;
        default: break;
        }

        StepEvent(pl);
        if (pl.HP <= 0) { std::printf("게임 오버\n"); break; }
    }
}
