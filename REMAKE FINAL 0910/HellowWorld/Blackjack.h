#pragma once
#include <cstddef>   // size_t
#include <cstdio>    // printf (���� �ʿ��� ���� ���� ����)

// ī�� �� ��
struct Card
{
    int  Value = 0;  // 1(A) ~ 13(K)
    char Suit = 0;  // 'S','H','D','C'

    // ��� �Լ��� �ڱ� �����͸� ���� �� const��
    bool IsAce() const { return Value == 1; }

    // J/Q/K�� 10��, A�� �켱 1��(11 ó���� �հ� �ܰ迡��)
    int GetCardValue() const { return Value > 10 ? 10 : Value; }
};

// �� �� �÷���(�ܺ� main���� ȣ��)
void PlayBlackjack();

// ���������������������������� ��/�ڵ� ��ƿ ����������������������������
void InitializeDeck(Card* deck);       // 52�� ����
void ShuffleDeck(Card* deck);          // �� ����(C++ ǥ�� ���� ���)

const Card& DrawCard(Card* deck, int& top);                           // top���� �� �� �̱�
void AddCardToHand(Card* hand, int& count, const Card& card);         // ���п� �� �� �߰�

// ���������������������������� ��� ����������������������������
void PrintHands(
    const Card* player, int pCount,
    const Card* dealer, int dCount,
    bool revealHole);
void PrintCard(const Card& c);
void PrintPlayerHand(const Card* hand, int count);
void PrintDealerHand(const Card* hand, int count, bool revealHole);

// ���������������������������� ����/��� ����������������������������
bool IsBlackjack(const Card* hand, int count); // 2��, A+10����
int  GetCardValue(const Card& c);              // ���� ����(ȣ�� �ϰ�����)
bool IsBust(const Card* hand, int count);      // 21 �ʰ� ����
int  GetBestScore(const Card* hand, int count);// A�� 11�� �°��ϸ� �ִ� 21 ���� ���� ��
bool IsSoft17(const Card* hand, int count);    // A�� 11�� �ļ� ��Ȯ�� 17�̸� true
