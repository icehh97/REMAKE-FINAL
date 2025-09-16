#include "Blackjack.h"
#include <algorithm>  // std::shuffle
#include <random>     // std::mt19937, std::random_device
#include <iostream>   // std::cin
#include <ctime>      // (선택) srand 용이었으나 지금은 미사용

// 최대 핸드 장수(여유 있게)
static const int MaxHand = 16; // 극단 상황 방지 차원에서 16장 정도 확보

// ──────────────────────────────────────────────────────────────
// 메인 게임 루프
// 규칙: 플레이어 먼저 행동, 버스트 즉시 패배,
//       딜러는 17 이상이면(소프트 17 포함) 스탠드
// ──────────────────────────────────────────────────────────────
void PlayBlackjack()
{
    // 1) 덱 준비
    Card deck[52];
    int  deckTop = 0;
    InitializeDeck(deck);
    ShuffleDeck(deck); // 매 실행마다 다른 순서(표준 RNG)

    // 2) 초기 배분(플레이어/딜러 각 2장)
    Card dealer[MaxHand]; int dCount = 0;
    Card player[MaxHand]; int pCount = 0;

    AddCardToHand(player, pCount, DrawCard(deck, deckTop));
    AddCardToHand(dealer, dCount, DrawCard(deck, deckTop));
    AddCardToHand(player, pCount, DrawCard(deck, deckTop));
    AddCardToHand(dealer, dCount, DrawCard(deck, deckTop));

    // 3) 오픈 출력(딜러 한 장 숨김)
    PrintHands(player, pCount, dealer, dCount, /*revealHole=*/false);

    // 4) 블랙잭 체크(양쪽 2장 상태에서만)
    const bool playerBJ = IsBlackjack(player, pCount);
    const bool dealerBJ = IsBlackjack(dealer, dCount);

    if (playerBJ && dealerBJ)
    {
        std::puts("둘 다 블랙잭! 무승부!");
        PrintHands(player, pCount, dealer, dCount, /*revealHole=*/true);
        return;
    }
    else if (playerBJ)
    {
        std::puts("플레이어 블랙잭! 승리!");
        PrintHands(player, pCount, dealer, dCount, /*revealHole=*/true);
        return;
    }
    else if (dealerBJ)
    {
        std::puts("딜러 블랙잭. 패배...");
        PrintHands(player, pCount, dealer, dCount, /*revealHole=*/true);
        return;
    }

    // 5) 플레이어 턴
    bool playerStand = false;
    while (!playerStand && !IsBust(player, pCount))
    {
        std::printf("플레이어 점수: %d\n", GetBestScore(player, pCount));
        std::printf("Hit(1) / Stand(2)? : ");

        // 입력 안전성: 잘못된 입력 클리어
        int input = 0;
        if (!(std::cin >> input))
        {
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            std::puts("숫자만 입력하세요. (1: Hit, 2: Stand)");
            continue;
        }
        if (input != 1 && input != 2)
        {
            std::puts("1 또는 2만 입력하세요.");
            continue;
        }

        if (input == 1) // Hit
        {
            AddCardToHand(player, pCount, DrawCard(deck, deckTop));
            PrintHands(player, pCount, dealer, dCount, /*revealHole=*/false);

            if (IsBust(player, pCount))
            {
                std::puts("플레이어 버스트! 패배!");
                PrintHands(player, pCount, dealer, dCount, /*revealHole=*/true);
                return;
            }
        }
        else // Stand
        {
            playerStand = true;
        }
    }

    // 6) 딜러 턴(소프트 17도 스탠드 규칙)
    std::puts("딜러 턴 시작...");
    PrintHands(player, pCount, dealer, dCount, /*revealHole=*/true);

    while (true)
    {
        const int best = GetBestScore(dealer, dCount);

        if (best > 21)
        {
            std::puts("딜러 버스트! 플레이어 승리!");
            return;
        }

        // 17 이상이면(하드/소프트 불문) 멈춤
        if (best >= 17)
        {
            // 참고 출력: 소프트 17 여부 표시(규칙 확인용)
            if (best == 17 && IsSoft17(dealer, dCount))
                std::puts("(참고) 딜러 소프트 17 → 규칙에 따라 스탠드");
            break;
        }

        // 16 이하면 히트
        AddCardToHand(dealer, dCount, DrawCard(deck, deckTop));
        std::printf("딜러 카드 추가: ");
        PrintDealerHand(dealer, dCount, /*revealHole=*/true);
        std::printf("\n");
    }

    // 7) 승패 판정(버스트 아닐 때 점수 비교)
    const int pScore = GetBestScore(player, pCount);
    const int dScore = GetBestScore(dealer, dCount);
    PrintHands(player, pCount, dealer, dCount, /*revealHole=*/true);
    std::printf("플레이어 점수: %d, 딜러 점수: %d\n", pScore, dScore);

    if (pScore > dScore)       std::puts("플레이어 승리!");
    else if (pScore < dScore)  std::puts("딜러 승리!");
    else                       std::puts("무승부!");
}

// ──────────────────────────────────────────────────────────────
// 덱/핸드 유틸
// ──────────────────────────────────────────────────────────────

// 52장 생성: Value(1~13) × Suit(4)
void InitializeDeck(Card* deck)
{
    const char suits[4] = { 'S','H','D','C' };
    int idx = 0;
    for (int v = 1; v <= 13; ++v)       // 1(A)~13(K)
        for (int s = 0; s < 4; ++s)
        {
            deck[idx].Value = v;
            deck[idx].Suit = suits[s];
            ++idx;
        }
}

// C++ 표준 셔플: rand()/srand() 대신 mt19937+shuffle
void ShuffleDeck(Card* deck)
{
    static std::mt19937 rng(std::random_device{}()); // 프로그램 전체에서 재사용
    std::shuffle(deck, deck + 52, rng);
}

// top에서 한 장 뽑기. 끝나면 자동 리셋+재셔플
const Card& DrawCard(Card* deck, int& top)
{
    if (top >= 52)
    {
        ShuffleDeck(deck);
        top = 0;
    }
    return deck[top++];
}

// 손패 추가(최대 길이 방지)
void AddCardToHand(Card* hand, int& count, const Card& card)
{
    if (count < MaxHand)
    {
        hand[count] = card;
        ++count;
    }
    else
    {
        // 정상 게임에선 거의 도달 불가. 안전 메시지.
        std::puts("[경고] 손패가 가득 찼습니다. (무시하고 진행)");
    }
}

// ──────────────────────────────────────────────────────────────
// 출력 계열
// ──────────────────────────────────────────────────────────────
void PrintHands(
    const Card* player, int pCount,
    const Card* dealer, int dCount,
    bool revealHole)
{
    std::printf("플레이어 카드 : ");
    PrintPlayerHand(player, pCount);
    std::printf("\n딜러 카드 : ");
    PrintDealerHand(dealer, dCount, revealHole);
    std::printf("\n");
}

void PrintCard(const Card& c)
{
    static const char* kValueStr[13] = {
        "A","2","3","4","5","6","7","8","9","10","J","Q","K"
    };
    std::printf("%c%s", c.Suit, kValueStr[c.Value - 1]);
}

void PrintPlayerHand(const Card* hand, int count)
{
    for (int i = 0; i < count; ++i)
    {
        PrintCard(hand[i]);
        std::printf(" ");
    }
}

void PrintDealerHand(const Card* hand, int count, bool revealHole)
{
    for (int i = 0; i < count; ++i)
    {
        if (i == 1 && !revealHole) std::printf("??");
        else                       PrintCard(hand[i]);
        std::printf(" ");
    }
}

// ──────────────────────────────────────────────────────────────
// 판정/계산
// ──────────────────────────────────────────────────────────────

// 블랙잭: 정확히 2장이고 (A + 10(J/Q/K/10))
bool IsBlackjack(const Card* hand, int count)
{
    if (count != 2) return false;
    const bool a0 = (hand[0].Value == 1);
    const bool a1 = (hand[1].Value == 1);
    const bool t0 = (GetCardValue(hand[0]) == 10);
    const bool t1 = (GetCardValue(hand[1]) == 10);
    return (a0 && t1) || (a1 && t0);
}

// 전역 함수(멤버와 일치): J/Q/K → 10, A → 1
int GetCardValue(const Card& c)
{
    const int v = c.Value;
    return (v > 10) ? 10 : v;
}

// 현재 합계가 21 초과인지
bool IsBust(const Card* hand, int count)
{
    return GetBestScore(hand, count) > 21;
}

// A를 11로 승격하며 21 이하 최대 합을 구함
int GetBestScore(const Card* hand, int count)
{
    int sum = 0;
    int ace = 0;
    for (int i = 0; i < count; ++i)
    {
        sum += GetCardValue(hand[i]);   // A는 1로 더함
        if (hand[i].IsAce()) ++ace;
    }

    // 가능한 한 많이(하지만 21을 넘지 않게) A를 11로 승격(= +10)
    while (ace > 0 && (sum + 10) <= 21)
    {
        sum += 10;
        --ace;
    }
    return sum;
}

// 소프트 17 판단: A를 11로 쳐서 "정확히 17"이 되는 경우만 true
bool IsSoft17(const Card* hand, int count)
{
    int raw = 0, aces = 0;
    for (int i = 0; i < count; ++i)
    {
        raw += GetCardValue(hand[i]);
        if (hand[i].IsAce()) ++aces;
    }

    bool usedAceAs11 = false;
    int best = raw;
    if (aces > 0 && raw + 10 <= 21)
    {
        best = raw + 10;
        usedAceAs11 = true;
    }

    return (best == 17) && usedAceAs11;
}
