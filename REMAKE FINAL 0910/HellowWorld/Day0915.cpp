#include <stdio.h>
#include <iostream>
#include "Day0915.h"
#include "�ָ�����.h"
#include "Blackjack.h"

void Day0915_WeekPractice()
{
	int Year = 0;
	int Month = 0;
	int Day = 0;
	printf("��¥�� �Է� �ϼ���(��: 2025 9 15) : ");
	std::cin >> Year >> Month >> Day;
	printf("�ش� ��¥�� [%s]�Դϴ�.\n", GetDayOfWeek(Year, Month, Day));
}

void Day0915_WeekPracticeTest()
{
	int Year = 2025;
	int Month = 11;
	int Day = 1;

	Month = 11;
	for (int i = 1; i < 31; i++)
	{
		Day = i;
		printf("(%d/%d/%d)�� [%s]�Դϴ�.\n", Year, Month, Day, GetDayOfWeek(Year, Month, Day));
	}

}

void Day0915_WeekPracticeBlackjack()
{
	PlayBlackjack();
}

void Day0915_WeekPracticeBlackjackTest()
{
	//'��', '��', '��', '��'
	Card Dealer[5] = { {10, 'S'}, {11, 'S'}, {1,'S'}, {5,'S'}, {3,'S'} };
	PrintDealerHand(Dealer, 5, true);
	printf("\n");
	PrintDealerHand(Dealer, 5, false);
}