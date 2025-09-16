#include "�ָ�����.h"

// �� ���� ��¥
const int DaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

// ����
const char* Week[7] = { "������", "ȭ����", "������", "�����", "�ݿ���", "�����", "�Ͽ���" };

const char* GetDayOfWeek(int Year, int Month, int Day)
{
	int Days = GetTotalDays(Year, Month, Day);
	return Week[Days % 7];
}

bool IsLeap(int Year)
{
	// 4�� ����� �����̴�. �׸��� 100�� ����� ������ �ƴϴ�.
	// �׷��� 400�� ����� �����̴�.
	// (Year % 4 == 0) : 4�� ����̴�. -> �����̴�.
	// (Year % 100 != 0) : 100�� ����� �ƴϴ� -> �����̴�.
	// (Year % 400 == 0) : 400�� ����̴� -> �����̴�.

	// 4�� ����̰� 100�� ����� �ƴϰų�, 400�� ����� �����̴�.
	return ((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0);
}

int GetTotalDays(int Year, int Month, int Day)
{
	int Days = 0;
	for (int Y = 1; Y < Year; Y++)
	{
		Days += (IsLeap(Y) ? 366 : 365);	// �����̸� 366�� �߰�, �ƴϸ� 365�� �߰�
	}
	for (int M = 1; M < Month; M++)
	{
		Days += DaysInMonth[M - 1];
		if (M == 2 && IsLeap(Year))
		{
			Days += 1;	// �����̸� 2���� �� �Ϸ� �߰�
		}
	}
	Day += (Day - 1);

	return Days;
}
