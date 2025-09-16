#include "Blackjack.h"
#include <algorithm>  // std::shuffle
#include <random>     // std::mt19937, std::random_device
#include <iostream>   // std::cin
#include <ctime>      // (����) srand ���̾����� ������ �̻��

// �ִ� �ڵ� ���(���� �ְ�)
static const int MaxHand = 16; // �ش� ��Ȳ ���� �������� 16�� ���� Ȯ��

// ����������������������������������������������������������������������������������������������������������������������������
// ���� ���� ����
// ��Ģ: �÷��̾� ���� �ൿ, ����Ʈ ��� �й�,
//       ������ 17 �̻��̸�(����Ʈ 17 ����) ���ĵ�
// ����������������������������������������������������������������������������������������������������������������������������
void PlayBlackjack()
{
    // 1) �� �غ�
    Card deck[52];
    int  deckTop = 0;
    InitializeDeck(deck);
    ShuffleDeck(deck); // �� ���ึ�� �ٸ� ����(ǥ�� RNG)

    // 2) �ʱ� ���(�÷��̾�/���� �� 2��)
    Card dealer[MaxHand]; int dCount = 0;
    Card player[MaxHand]; int pCount = 0;

    AddCardToHand(player, pCount, DrawCard(deck, deckTop));
    AddCardToHand(dealer, dCount, DrawCard(deck, deckTop));
    AddCardToHand(player, pCount, DrawCard(deck, deckTop));
    AddCardToHand(dealer, dCount, DrawCard(deck, deckTop));

    // 3) ���� ���(���� �� �� ����)
    PrintHands(player, pCount, dealer, dCount, /*revealHole=*/false);

    // 4) ���� üũ(���� 2�� ���¿�����)
    const bool playerBJ = IsBlackjack(player, pCount);
    const bool dealerBJ = IsBlackjack(dealer, dCount);

    if (playerBJ && dealerBJ)
    {
        std::puts("�� �� ����! ���º�!");
        PrintHands(player, pCount, dealer, dCount, /*revealHole=*/true);
        return;
    }
    else if (playerBJ)
    {
        std::puts("�÷��̾� ����! �¸�!");
        PrintHands(player, pCount, dealer, dCount, /*revealHole=*/true);
        return;
    }
    else if (dealerBJ)
    {
        std::puts("���� ����. �й�...");
        PrintHands(player, pCount, dealer, dCount, /*revealHole=*/true);
        return;
    }

    // 5) �÷��̾� ��
    bool playerStand = false;
    while (!playerStand && !IsBust(player, pCount))
    {
        std::printf("�÷��̾� ����: %d\n", GetBestScore(player, pCount));
        std::printf("Hit(1) / Stand(2)? : ");

        // �Է� ������: �߸��� �Է� Ŭ����
        int input = 0;
        if (!(std::cin >> input))
        {
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            std::puts("���ڸ� �Է��ϼ���. (1: Hit, 2: Stand)");
            continue;
        }
        if (input != 1 && input != 2)
        {
            std::puts("1 �Ǵ� 2�� �Է��ϼ���.");
            continue;
        }

        if (input == 1) // Hit
        {
            AddCardToHand(player, pCount, DrawCard(deck, deckTop));
            PrintHands(player, pCount, dealer, dCount, /*revealHole=*/false);

            if (IsBust(player, pCount))
            {
                std::puts("�÷��̾� ����Ʈ! �й�!");
                PrintHands(player, pCount, dealer, dCount, /*revealHole=*/true);
                return;
            }
        }
        else // Stand
        {
            playerStand = true;
        }
    }

    // 6) ���� ��(����Ʈ 17�� ���ĵ� ��Ģ)
    std::puts("���� �� ����...");
    PrintHands(player, pCount, dealer, dCount, /*revealHole=*/true);

    while (true)
    {
        const int best = GetBestScore(dealer, dCount);

        if (best > 21)
        {
            std::puts("���� ����Ʈ! �÷��̾� �¸�!");
            return;
        }

        // 17 �̻��̸�(�ϵ�/����Ʈ �ҹ�) ����
        if (best >= 17)
        {
            // ���� ���: ����Ʈ 17 ���� ǥ��(��Ģ Ȯ�ο�)
            if (best == 17 && IsSoft17(dealer, dCount))
                std::puts("(����) ���� ����Ʈ 17 �� ��Ģ�� ���� ���ĵ�");
            break;
        }

        // 16 ���ϸ� ��Ʈ
        AddCardToHand(dealer, dCount, DrawCard(deck, deckTop));
        std::printf("���� ī�� �߰�: ");
        PrintDealerHand(dealer, dCount, /*revealHole=*/true);
        std::printf("\n");
    }

    // 7) ���� ����(����Ʈ �ƴ� �� ���� ��)
    const int pScore = GetBestScore(player, pCount);
    const int dScore = GetBestScore(dealer, dCount);
    PrintHands(player, pCount, dealer, dCount, /*revealHole=*/true);
    std::printf("�÷��̾� ����: %d, ���� ����: %d\n", pScore, dScore);

    if (pScore > dScore)       std::puts("�÷��̾� �¸�!");
    else if (pScore < dScore)  std::puts("���� �¸�!");
    else                       std::puts("���º�!");
}

// ����������������������������������������������������������������������������������������������������������������������������
// ��/�ڵ� ��ƿ
// ����������������������������������������������������������������������������������������������������������������������������

// 52�� ����: Value(1~13) �� Suit(4)
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

// C++ ǥ�� ����: rand()/srand() ��� mt19937+shuffle
void ShuffleDeck(Card* deck)
{
    static std::mt19937 rng(std::random_device{}()); // ���α׷� ��ü���� ����
    std::shuffle(deck, deck + 52, rng);
}

// top���� �� �� �̱�. ������ �ڵ� ����+�����
const Card& DrawCard(Card* deck, int& top)
{
    if (top >= 52)
    {
        ShuffleDeck(deck);
        top = 0;
    }
    return deck[top++];
}

// ���� �߰�(�ִ� ���� ����)
void AddCardToHand(Card* hand, int& count, const Card& card)
{
    if (count < MaxHand)
    {
        hand[count] = card;
        ++count;
    }
    else
    {
        // ���� ���ӿ��� ���� ���� �Ұ�. ���� �޽���.
        std::puts("[���] ���а� ���� á���ϴ�. (�����ϰ� ����)");
    }
}

// ����������������������������������������������������������������������������������������������������������������������������
// ��� �迭
// ����������������������������������������������������������������������������������������������������������������������������
void PrintHands(
    const Card* player, int pCount,
    const Card* dealer, int dCount,
    bool revealHole)
{
    std::printf("�÷��̾� ī�� : ");
    PrintPlayerHand(player, pCount);
    std::printf("\n���� ī�� : ");
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

// ����������������������������������������������������������������������������������������������������������������������������
// ����/���
// ����������������������������������������������������������������������������������������������������������������������������

// ����: ��Ȯ�� 2���̰� (A + 10(J/Q/K/10))
bool IsBlackjack(const Card* hand, int count)
{
    if (count != 2) return false;
    const bool a0 = (hand[0].Value == 1);
    const bool a1 = (hand[1].Value == 1);
    const bool t0 = (GetCardValue(hand[0]) == 10);
    const bool t1 = (GetCardValue(hand[1]) == 10);
    return (a0 && t1) || (a1 && t0);
}

// ���� �Լ�(����� ��ġ): J/Q/K �� 10, A �� 1
int GetCardValue(const Card& c)
{
    const int v = c.Value;
    return (v > 10) ? 10 : v;
}

// ���� �հ谡 21 �ʰ�����
bool IsBust(const Card* hand, int count)
{
    return GetBestScore(hand, count) > 21;
}

// A�� 11�� �°��ϸ� 21 ���� �ִ� ���� ����
int GetBestScore(const Card* hand, int count)
{
    int sum = 0;
    int ace = 0;
    for (int i = 0; i < count; ++i)
    {
        sum += GetCardValue(hand[i]);   // A�� 1�� ����
        if (hand[i].IsAce()) ++ace;
    }

    // ������ �� ����(������ 21�� ���� �ʰ�) A�� 11�� �°�(= +10)
    while (ace > 0 && (sum + 10) <= 21)
    {
        sum += 10;
        --ace;
    }
    return sum;
}

// ����Ʈ 17 �Ǵ�: A�� 11�� �ļ� "��Ȯ�� 17"�� �Ǵ� ��츸 true
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
