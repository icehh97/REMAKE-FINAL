#pragma once
#include <cstddef>   // size_t
#include <cstdio>    // printf (선언만 필요할 때도 포함 권장)

// 카드 한 장
struct Card
{
    int  Value = 0;  // 1(A) ~ 13(K)
    char Suit = 0;  // 'S','H','D','C'

    // 멤버 함수는 자기 데이터만 읽을 때 const로
    bool IsAce() const { return Value == 1; }

    // J/Q/K는 10점, A는 우선 1점(11 처리는 합계 단계에서)
    int GetCardValue() const { return Value > 10 ? 10 : Value; }
};

// 한 판 플레이(외부 main에서 호출)
void PlayBlackjack();

// ────────────── 덱/핸드 유틸 ──────────────
void InitializeDeck(Card* deck);       // 52장 생성
void ShuffleDeck(Card* deck);          // 덱 섞기(C++ 표준 셔플 사용)

const Card& DrawCard(Card* deck, int& top);                           // top에서 한 장 뽑기
void AddCardToHand(Card* hand, int& count, const Card& card);         // 손패에 한 장 추가

// ────────────── 출력 ──────────────
void PrintHands(
    const Card* player, int pCount,
    const Card* dealer, int dCount,
    bool revealHole);
void PrintCard(const Card& c);
void PrintPlayerHand(const Card* hand, int count);
void PrintDealerHand(const Card* hand, int count, bool revealHole);

// ────────────── 판정/계산 ──────────────
bool IsBlackjack(const Card* hand, int count); // 2장, A+10인지
int  GetCardValue(const Card& c);              // 전역 버전(호출 일관성용)
bool IsBust(const Card* hand, int count);      // 21 초과 여부
int  GetBestScore(const Card* hand, int count);// A를 11로 승격하며 최대 21 이하 최적 합
bool IsSoft17(const Card* hand, int count);    // A를 11로 쳐서 정확히 17이면 true
