#include "Day0908.h"
#include <stdio.h>
#include <limits.h>
#include <random>

void Day0908()
{
	int a = 10;
	int Array[5];	// int 5���� �����ϴ� �迭
	Array[0] = 10;	// �迭�� ù��° ��ҿ� 10�� �����Ѵ�.
	Array[3] = 40;	// �迭�� �׹�° ��ҿ� 40�� �����Ѵ�.

	int Array2[5] = { 1,2,3,4,5 };
	int Array3[5] = { 1,2,3 };
	int Array4[5] = { 0 };

	const int Size = 5;
	int Array5[Size] = {};
	//sizeof(Array5);	// Array5�� ��ü ����Ʈ ũ�⸦ �� �� �ִ�.
	//sizeof(Array5[0]);	// Array5�� ��� �ϳ��� ũ�⸦ �� �� �ִ�.
	int ElementCount = sizeof(Array5) / sizeof(Array5[0]);	// Array5�� ��� ����

	//int Size2 = 5;
	//int Array6[Size2] = {};	// �迭 ������ �� ũ�⸦ ������ ������ ���� ����.

	// Array[5] = 60;	// ���ۿ�����. �迭 ���� ���� �����Ϸ��� �ϱ� ������ ������ �߻��Ѵ�.

	// ���� �ǽ�
	// 1. �迭 ����� �ʱ�ȭ �غ���
	// 2. �迭�� ��� ����� ���� ���ϰ� ��� ���ϱ�
	// 3. �迭�� ��� ��� �� �ִ밪�� �ּҰ� ���ϱ�

	// 1.
	int Numbers[3] = { 5, 8, 3 };

	// 2. 
	int Sum = 0;
	float Average = 0.0f;
	int ArrayCount = static_cast<int>(sizeof(Numbers) / sizeof(Numbers[0]));
	for (int i = 0; i < ArrayCount; i++)
	{
		Sum += Numbers[i];
	}
	Average = Sum / static_cast<float>(ArrayCount);
	printf("����� %.2f�Դϴ�.\n", Average);

	int MaxNumber = INT_MIN;
	int MinNumber = INT_MAX;
	for (int i = 0; i < ArrayCount; i++)
	{
		if (MaxNumber < Numbers[i])
		{
			MaxNumber = Numbers[i];
		}
		if (MinNumber > Numbers[i])
		{
			MinNumber = Numbers[i];
		}
	}

	int Array6[4][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {0,1,2} };
	int test = Array6[1][2];	// test = 6
	int Array7[12] = { 1,2,3,4,5,6,7,8,9,0,1,2 };

	Shuffle(Array7, 12);

	int i = 0;
}

void Day0908_Cast()
{
	// ĳ��Ʈ(Cast)
	int a = 10;
	float b = 15.5f;

	a = (int)b;	// b�� int������ ĳ�����ؼ� a�� �����Ѵ�. (C��Ÿ��, ����� ĳ����)
	a = b;		// b�� a�� �����Ѵ�. �׷��� a�� b�� Ÿ���� �ٸ��ϱ� b�� a�� �Ͻ������� ĳ�����ؼ� �����Ѵ�.(C��Ÿ��, �Ͻ��� ĳ����)
	b = a;		// �Ͻ��� ĳ������ ��ü�� ǥ���� �����ʿ��� ū�����δ� �������� ��찡 ����.

	// C++ ĳ����
	// static_cast : C��Ÿ�� ĳ������ �����ϰ� ���� ��. ������ Ÿ�ӿ� ������
	// dynamic_cast : ������(Ŭ���� ���Ŀ�)
	// const_cast : const �Ӽ��� �����ϰų� �߰��ϴµ� ���. ������� �ʴ� ���� ����.
	// reinterpret_cast : C��Ÿ�� ĳ���ÿ��� ������ �κ�. ���� Ÿ���� ������ �����ϰ� �� Ÿ������ �ؼ��ϰ� �Ѵ�.

	a = static_cast<int>(b);	// b�� int������ ĳ�����ؼ� a�� �����Ѵ�. (C++��Ÿ��, ����� ĳ����)

}

void Shuffle(int Array[], int Length)
{
	/*
	* 1. �迭�� ������ ��ҿ��� ù ��ұ��� ��ȸ.
	* 2. ���� ����� �ε���(i)�� , 0~i �� ������ �ε���(j)�� �����Ѵ�.
	* 3. i��° ��ҿ� j��° ��Ҹ� ���� ��ȯ
	* 4. i�� 0�� �� ������ �ݺ�
	*/

	for (int i = Length - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		int Temp = Array[i];
		Array[i] = Array[j];
		Array[j] = Temp;
	}
}

void TestRef(int& OutData, const int& ReadData)
{
	OutData *= ReadData;
	//ReadData = 10;
}

void Day0908_Ref()
{
	int Number = 10;
	int Number2 = 2;
	int& Ref = Number;	// Number�� ������ Ref��.
	//
	
	TestRef(Number, Number2);

	int i = 0;
	
}
