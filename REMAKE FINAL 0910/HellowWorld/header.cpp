#include <stdio.h>
#include <iostream>
#include "header.h"

// ���Ǻ� : ����� ������ ���� ��� �����ϴ� ���� �����س��� ��

void TestClass::TestFunc()
{
	// ���� ����
}

void OldTales()
{
	//printf("Hello\tWorld!\n");		// C����� ��� ���
	//printf("\"����\"\t");			// ""�ȿ� \n�� ������ ���� �ٲٶ�� �ǹ�(
	//printf("82����Դϴ�.�������á�\n");

	//// �̽������� ������
	//// \n : �ٹٲٱ�(���๮��)
	//// \t : �� �ֱ�
	//// \" : �ֵ���ǥ �Ѱ�
	//// \\ : \���
	//// \r : ĳ���� ����(�����쿡���� �߿����� ����. ������������ �߿���)
	//	
	////std::cout << "Hello World!\n";	// C++ ��� ���

	//// number��� �̸��� ���� int(��Ƽ��)������ �����ϰ� �ű⿡ 0�� �����Ѵ�.
	//int number;	// ���� ����.
	//number = 0;	// ������ ���� ����.

	//// int : ������(�Ҽ����� ���� ����, 5, 10, -2, 0, 66 ...)
	//number = 5.3; // number���� 5�� ����ȴ�.
	//number = 5 / 2;	// number���� 2�� ����ȴ�.

	////

	//scanf("%d", &number);	// ���ڸ� �ϳ� �Է� �ޱ�(C)
	//printf("�Է��� ���ڴ�(C) : %d\n", number);

	//std::cin >> number;		// ���ڸ� �ϳ� �Է� �ޱ�(C++)
	//printf("�Է��� ���ڴ�(C++) : %d\n", number);

	// /*���α׷��� �������� �� ���̸� ����� �Է¹��� ���ڸ� �״�� ����غ���

	// �߰��߰��߰��߰��߰��߰��߰��߰��߰�

	// �߰��߰��߰��߰��߰��߰��߰��߰��߰�2

	// �ǽ��ǽ�
	// �ǽ��ǽ�*/

	//int number1 = 0;
	//int number2 = 0;
	//printf("���� 1�� �Է��Ͻÿ� : ");
	//std::cin >> number1;
	//printf("���� 2�� �Է��Ͻÿ� : ");
	//std::cin >> number2;
	//int number3 = number1 + number2;
	//printf("�� ������ ���� %d�Դϴ�.", number3);

	//float number1 = 10.0f;	// 10�̶�� float Ÿ���� ���� float�� numnber1�� �ֱ�
	//float number2 = 15.0;	// 15��� double Ÿ���� ���� float�� number2�� �ֱ�

	//std::cin >> number1 >> number2;
	//printf("number1 : %f\nnumber2 : %.2f", number1, number2);

	//// ���ܽǽ� : ���� �������� �Է� �ް� ���� ���ϱ�
	//const float Pi = 3.141592f;	// ����� �����ϰ� ����
	//float radius = 0.0f;
	//printf("���� �������� �Է��ϼ��� : ");
	//std::cin >> radius;
	//printf("���� ���̴� [%f]�Դϴ�.\n", radius * radius * Pi);


	//int square = 0;
	//printf("���簢���� �Ѻ��� ���̸� �Է��ϼ��� : ");
	//std::cin >> square;
	//printf("���簢���� ���̴� [%d]�Դϴ�.", square * square);
	//// �����÷ο� �߻��� �� ����

	//float a = 123.0f;
	//float b = 0.0f;
	//std::cin >> b;
	//b = b * 123.0f;

	//bool result = a == b;	// F9 : �극��ũ ����Ʈ ����/����

	//float Ÿ���� ==�� ���� �� �ݵ�� �Ʒ��� ���� �����ؾ���.
	//float epsilon = 0.001f;
	//a < (b + epsilon);
	//a > (b - epsilon);

	// if : �Ұ�ȣ ���� true�� �߰�ȣ ���� �ڵ带 �����϶�.
	//		���� Ư�� ������ ������ ���� � �ڵ带 �����ϰ� ���� �� ���.

	//int a = 10;
	//int b = 0;
	//printf("a�� 10\nb�� �Է��ϼ��� : ");
	//std::cin >> b;

	//if (a > b)
	//{
	//	printf("if�� �����ߴ�.\n");
	//	printf("b�� %d�� a�� �� ũ��\n", b);
	//}

	//if (a <= b)
	//{
	//	printf("b�� %d�� a�� �� �۰ų�����\n", b);
	//}

	//// if-else : �̰� �ƴϸ� �����϶� ���.
	//if (a > b)
	//{
	//	printf("a�� b���� ũ��.\n");
	//}
	//else
	//{
	//	printf("a�� b���� �۰ų� ����.\n");
	//}

	// (a != b) : a�� b�� �ٸ���.

	//if (b < 60)
	//{
	//	//F
	//}
	//else if (b < 70)
	//{
	//	//D
	//}
	//else if(b < 80)
	//{
	//	//C
	//}
	//else if (b < 90)
	//{
	//	//B
	//}
	//else
	//{
	//	//A
	//}

	//int a = 0;
	//std::cin >> a;
	//switch (a)
	//{
	//case 1:
	//	printf("1�̴�.\n");
	//	break;
	//case 3:
	//	printf("3�̴�.\n");
	//	break;
	//case 5:
	//	printf("5�̴�.\n");
	//	break;
	//default:
	//	printf("1,3,5�� �ƴϴ�.\n");
	//	break;
	//}

	//int a = 10;
	//int b = 20;
	//int c = 0;
	//if (a > b)
	//{
	//	c = a * 2 + b;
	//}
	//else
	//{
	//	c = a + b * 2;
	//}
	//c = (a > b) ? (a * 2 + b) : (a + b * 2); // ���׿�����

	//int a = 10;
	//if (a > 5 && !(10 > a))
	//{
	//	// ����
	//}
	//else
	//{
	//	// ����
	//}

	////1. ���ڸ� �Է¹޾� ������� �������� 0���� ����ϱ�
	//int InputNumber = 0;	
	//printf("���ڸ� �Է��ϼ��� : ");
	//std::cin >> InputNumber;
	//if (InputNumber > 0)
	//{
	//	printf("�Է��� ���ڴ� ����Դϴ�.\n");
	//}
	//else if(InputNumber < 0)
	//{
	//	printf("�Է��� ���ڴ� �����Դϴ�.\n");
	//}
	//else
	//{
	//	printf("�Է��� ���ڴ� 0�Դϴ�.\n");
	//}
	//// if�� ������ ū���� ���� üũ�ǰ� �ϱ�
	//// ������ ����ϱ� ������ �����ϱ�
	//
	////2. ���ڸ� �Է¹޾� Ȧ������ ¦������ ����ϱ�
	//printf("Ȧ¦�� �Ǻ��ϱ� ���� ���ڸ� �Է��ϼ��� : ");
	//std::cin >> InputNumber;
	//if (InputNumber % 2 == 0)
	//{
	//	printf("¦���� �Է��߽��ϴ�.\n");
	//}
	//else
	//{
	//	printf("Ȧ���� �Է��߽��ϴ�.\n");
	//}
	//
	////3. �� ���� �Է� �޾� �� ū ���� ����ϱ�.���� ���� ���ٰ� ���.
	//int Number1 = 0;
	//int Number2 = 0;
	//printf("�� ū���� Ȯ���ϱ� ���� ���� �ΰ��� �Է��ϼ��� : ");
	//std::cin >> Number1 >> Number2;
	//if (Number1 > Number2)
	//{
	//	printf("ù��° ���ڰ� �� Ů�ϴ�.\n");
	//}
	//else if (Number2 > Number1)
	//{
	//	printf("�ι�° ���ڰ� �� Ů�ϴ�.\n");
	//}
	//else
	//{
	//	printf("�� ���� ���� ���Դϴ�.\n");
	//}

	////4. ���̿� Ű�� �Է� �޾�, 6�� �̻�, 120cm �̻��� ��
	////		�ѷ��ڽ��� ž�� ����, �� �ܿ��� �Ұ������� ���
	//const unsigned int LimitAge = 5;
	//const float LimitHeight = 120.0f;
	//unsigned int Age = 0;
	//float Height = 0;	// �Ͻ��� ��ȯ(���� ��ȯ���ִ°�, ���� ǥ�������� ū������ �����)
	//printf("���̸� �Է��ϼ��� : ");
	//std::cin >> Age;
	//printf("Ű�� �Է��ϼ��� : ");
	//std::cin >> Height;
	//if (Age > LimitAge && Height >= LimitHeight)
	//{
	//	printf("�ѷ��ڽ��� ž�� ����!\n");
	//}
	//else
	//{
	//	printf("�ѷ��ڽ��� ž�� �Ұ���!\n");
	//}
	//
	////5. ������ �Է� �޾� 90�� �̻��� A, 80�� �̻��� B, 70�� �̻��� C, 
	////		60�� �̻��� D, �� ���ϴ� F��� ����ϱ�
	//
	////6. �� ������ ������ �Է¹޾�, �� ���� ����� 60�� �̻��̸� 
	////		"�հ�", �ƴϸ� "���հ�"�� ���
	////		, �� �Ѱ����̶� 40�� �̸��̸� ���հ� ����ϱ�
	//int Point1 = 0;
	//int Point2 = 0;
	//int Point3 = 0;
	//printf("���� ������ 3�� �Է��� �ּ��� : ");
	//std::cin >> Point1 >> Point2 >> Point3;
	//const int AverageLimit = 60;
	//const int FailLimit = 40;
	//float Avergage = (Point1 + Point2 + Point3) / 3.0f;
	//if ((Avergage >= AverageLimit) &&
	//	(Point1 >= FailLimit && Point2 >= FailLimit && Point3 >= FailLimit))
	//{
	//	printf("�հ�\n");
	//}
	//else
	//{
	//	printf("���հ�\n");
	//}

	//int flag = 0b1010;	
	//// 0b0001	= ���� Ű�� ��������.
	//// 0b0010	= ������ Ű�� ��������.
	//// 0b0100	= ���� Ű�� ��������.
	//// 0b1000	= �Ʒ��� Ű�� ��������.

	//if ((flag & 0b0010) != 0b0000)
	//{
	//	// ������ Ű�� ������ �ִ�.
	//}
	//else
	//{
	//	// ������ Ű�� ������ ���� �ʴ�.
	//}

	////int flag = 0b1010;	
	//flag = flag | 0b0001;	// ����� flag = 0b1011;

	////int flag =        0b1010;
	//int result = flag ^ 0b0001; // ��� = 0b1011;
	//result = 0b1011 ^ 0b0001;	// ��� = 0b1010;

	//flag = 0b1010;
	//int test = 0b0001;
	//test = ~test;	// ���� Ű�� ������ ������ ��� ����

	//// enum : ����鿡�� ����� �˾ƺ��� ���� �̸��� �ٿ� ���� ��
	//enum Key
	//{
	//	Up		= 1 << 0,	// 0b0001
	//	Down	= 1 << 1,	// 0b0010
	//	Left	= 1 << 2,	// 0b0100
	//	Right	= 1 << 3	// 0b1000
	//};

	//if ((flag & Up) != 0)
	//{
	//	// Up��ư�� �������ִ�.
	//}

	//// ���� �ǽ� : ����� �ϳ� �Է¹ް� Ȧ������ ¦������ ����ϱ�(%������)
	//int InputNumber = 0;
	//printf("�׽�Ʈ�� ���� �Է��ϼ��� : ");
	//std::cin >> InputNumber;
	//if ((InputNumber & 1) != 0)
	//{
	//	printf("Ȧ���� �Է��߽��ϴ�.\n");
	//}
	//else
	//{
	//	printf("¦���� �Է��߽��ϴ�.\n");
	//}

	////��� ���� 10�����(for)
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("Hello World For: %d\n", i);
	//}

	//int Count = 1;
	//while ((Count % 3) != 0)	// while()�� ������ ���̸� �ڵ� �� ����
	//{
	//	printf("Hello World While: %d\n", Count);
	//	Count++;
	//}

	//Count = 1;
	//do
	//{
	//	printf("Hello World While: %d\n", Count);
	//	Count++;
	//} while ((Count % 3) != 0);	// �ϴ� �ѹ� �����ϰ� while()�� ������ ���̸� �ڵ� �� ����

	// ���� �ǽ�
	// 1. 0�� �Է¹��� ������ �Է��� ��� �ް�, 0�� �ԷµǸ� �Է¹��� ������ ���� ����ϱ�
	//		while�̶� do-while��� �غ���	
	//int InputNumer = -1;
	//int Sum = 0;
	//while (true)	
	//{
	//	std::cin >> InputNumer;		
	//	Sum += InputNumer;	//Sum = Sum + InputNumer;

	//	if (InputNumer == 0)
	//		break;
	//}
	//printf("�Է¹��� ������ �� = %d", Sum);

	// 2. �Է¹��� ������, ������ ����غ���
	//int InputNumber = 0;
	//printf("������ �ܼ��� �Է��ϼ��� : ");
	//std::cin >> InputNumber;
	//for (int i = 1; i < 10; i++)
	//{
	//	printf("%d * %d = %d\n", InputNumber, i, InputNumber * i);
	//}

	// 3. ���ڸ� �ϳ� �Է� �ް�, 0���� �Է¹��� ������ �ִ� ���� ��, Ȧ���� ����ϱ�
	//int InputNumber = 0;
	//printf("�ִ�ġ�� �Է��ϼ��� : ");
	//std::cin >> InputNumber;
	//InputNumber++;	// for������ ���ǿ� <=�� ���� �Ⱦ 1 ����.
	//for (int i = 0; i < InputNumber; i++)
	//{
	//	if ((i % 2) == 0)
	//	{
	//		continue;
	//	}
	//	printf("%d�� Ȧ���Դϴ�.\n", i);
	//}

	// 4. 1~100������ ���� �߿� 7�� ����� ����ϱ�
	//const int MinNumber = 1;
	//const int MaxNumber = 100;
	//for (int i = 1; i <= MaxNumber; i++)
	//{
	//	if ((i % 7) == 0)
	//	{
	//		printf("%d�� 7�� ����Դϴ�.\n", i);
	//	}
	//}

	// 5. �Է¹��� ���ڸ�ŭ�� ���� ���� �Ƕ�̵� �׸���
	//		3�� �Է¹޾����� �Ʒ��� ���� ����ϱ�
	//			  *
	//			 ***
	//			*****
	// 5-1. �Է��� �޾ƾ� �Ѵ�.(InputNumber)
	// 5-2. *ǥ�� ù��° �������� 1�� �ι�° �������� 3��.. �̷������� �̾�����
	//		�������� (����*2 + 1)��ŭ�� *�� ���� �Ѵ�.
	// 5-3. �� ������ " "�� (������-(���� ����+1))��ŭ �߰��ؾ� �Ѵ�.
	//int InputNumber = 0;
	//printf("�Ƕ�̵� ������ �Է��ϼ��� : ");
	//std::cin >> InputNumber;

	//for (int i = 0; i < InputNumber; i++)
	//{
	//	for (int j = 0; j < (InputNumber - (i + 1)); j++)
	//	{
	//		printf(" ");
	//	}
	//	for (int k = 0; k < (i * 2 + 1); k++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}

	//// C ��Ÿ���� ���� ����
	////srand(time(0));
	//srand(0);
	//for (int i = 0; i < 10; i++)
	//{
	//	int RandomNumber = rand();
	//	printf("������ ���� : %d\n", RandomNumber);
	//}

	//// 0~5������ ���ڸ� �������� ���ϰ� �ʹ�.
	//int RandomNumber1 = rand() % 6;

	//// 1~6������ ���ڸ� �������� ���ϰ� �ʹ�.
	//int RandomNumber2 = rand() % 6 + 1;

	//// C++ ��Ÿ��
	//std::random_device RandomDivece;
	//std::mt19937 Generate(RandomDivece());

	//printf("�յ���� : ");
	//std::uniform_int_distribution<> uniformDis(1, 100);
	//for (int i = 0; i < 10; i++)
	//{
	//	int Number = uniformDis(Generate);
	//	printf("%d", Number);
	//	if (i < 9)
	//	{
	//		printf(", ");
	//	}
	//}
	//printf("\n");

	//printf("���Ժ��� : ");
	//std::normal_distribution<> normalDis(80, 10);
	//for (int i = 0; i < 10; i++)
	//{
	//	float fNumber = normalDis(Generate);
	//	printf("%.2f", fNumber);
	//	if (i < 9)
	//	{
	//		printf(", ");
	//	}
	//}
	//printf("\n");


	////4��

	//enum Item
	//{
	//	KeyRed = 1,		// 1 << 0
	//	KeyGreen = 2,	// 1 << 1
	//	KeyBlue = 4		// 1 << 2
	//};
	//int Inventory = 0;
	//
	//// �κ��丮 ���� ����ϱ�(Inventory�� ��Ʈ���뿡 ���� ���)
	//// 1�� : ������ �߰�, 2�� : ������ ������, 3�� : ����
	//// �̹� �ִ� �������� �߰��Ϸ����ϸ� "�̹� �ִ� �������Դϴ�" ���
	//// ���� �������� ���������ϸ� "���� �������Դϴ�." ���

	
}

void Day0905()
{
	/*
		1. �ֻ���(1~6)��, 100���� ������, 6�� ��� ���Դ���, ī�����ؼ�, ����ϱ�
	*/
	const int TestCount = 1000000;
	int HitCount = 0;
	for (int i = 0; i < TestCount; i++)	// 100���� ������
	{
		int dice = rand() % 6 + 1;	// �ֻ���(1~6)��
		if (dice == 6)	// 6�� ��� ���Դ���
		{
			HitCount++;	// ī�����ؼ�
		}
	}
	printf("6�� ���� ȸ�� = %d", HitCount);	// ����ϱ�

	/*
		2. ����, ����, �� ���� �����
			3������
			enum Ȱ��

			���� ���� ��
			 - �θ��� �÷��̾ ����,����,�� �� �ϳ��� �����Ѵ�.
			 - ������ ����� ���� �°� �а� ������.
			 - ������ ���� �̱��.
			 - ������ ������ �̱��.
			 - ���� ������ �̱��.
	*/
	enum RockPaperScissors
	{
		Scissors,
		Rock,
		Paper,
		NumOfRps
	};
	const int WinGoal = 3;
	int PlayerWinCount = 0;
	int ComWinCount = 0;

	while (PlayerWinCount < WinGoal && ComWinCount < WinGoal)
	{
		int PlayerSelect = -1;
		while (true)	// �÷��̾� ����
		{
			printf("�����ϼ���. [0:����, 1:����, 2:��] : ");
			std::cin >> PlayerSelect;

			if (PlayerSelect == Scissors
				|| PlayerSelect == Rock
				|| PlayerSelect == Paper)
			{
				break;
			}

			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���\n");
		}
		int ComSelect = rand() % NumOfRps;	// ��ǻ�� ����

		switch (PlayerSelect)	// ���� ����
		{
		case Scissors:
			if (ComSelect == Scissors)
			{
				printf("����� [����]�� �����߰� ��ǻ�ʹ� [����]�� �����߽��ϴ�.\n");
				printf("�����ϴ�.\n");
			}
			else if (ComSelect == Rock)
			{
				printf("����� [����]�� �����߰� ��ǻ�ʹ� [����]�� �����߽��ϴ�.\n");
				printf("����� �����ϴ�.\n");
				ComWinCount++;
			}
			else if (ComSelect == Paper)
			{
				printf("����� [����]�� �����߰� ��ǻ�ʹ� [��]�� �����߽��ϴ�.\n");
				printf("����� �̰���ϴ�.\n");
				PlayerWinCount++;
			}
			else
			{
				printf("ERROR!!!!! ������� ����� �߻���!\n");
			}
			break;
		case Rock:
			if (ComSelect == Scissors)
			{
				printf("����� [����]�� �����߰� ��ǻ�ʹ� [����]�� �����߽��ϴ�.\n");
				printf("����� �̰���ϴ�.\n");
				PlayerWinCount++;
			}
			else if (ComSelect == Rock)
			{
				printf("����� [����]�� �����߰� ��ǻ�ʹ� [����]�� �����߽��ϴ�.\n");
				printf("�����ϴ�.\n");
			}
			else if (ComSelect == Paper)
			{
				printf("����� [����]�� �����߰� ��ǻ�ʹ� [��]�� �����߽��ϴ�.\n");
				printf("����� �����ϴ�.\n");
				ComWinCount++;
			}
			else
			{
				printf("ERROR!!!!! ������� ����� �߻���!\n");
			}
			break;
		case Paper:
			if (ComSelect == Scissors)
			{
				printf("����� [��]�� �����߰� ��ǻ�ʹ� [����]�� �����߽��ϴ�.\n");
				printf("����� �����ϴ�.\n");
				ComWinCount++;
			}
			else if (ComSelect == Rock)
			{
				printf("����� [��]�� �����߰� ��ǻ�ʹ� [����]�� �����߽��ϴ�.\n");
				printf("����� �̰���ϴ�.\n");
				PlayerWinCount++;
			}
			else if (ComSelect == Paper)
			{
				printf("����� [��]�� �����߰� ��ǻ�ʹ� [��]�� �����߽��ϴ�.\n");
				printf("�����ϴ�.\n");
			}
			else
			{
				printf("ERROR!!!!! ������� ����� �߻���!\n");
			}
			break;
		default:
			printf("ERROR!!!!! ������� ����� �߻���!\n");
			break;
		}

		printf("Player = [%d], COM = [%d]\n", PlayerWinCount, ComWinCount);
	}

	if (PlayerWinCount >= WinGoal)
	{
		printf("����� ��ǻ�͸� �̰���ϴ�!\n");
	}
	else
	{
		printf("����� ��ǻ�Ϳ��� �����ϴ�...\n");
	}


	/*
		3. ���� �ο�
			��ǻ�Ͱ� 1~100 ������ ������ ���ڸ� �����ϰ�,
			����ڰ� ���� ������ �Է��� �޾� "�� ����", "�� ����" ���� ��Ʈ�� �����ϴ� ����
			5���ȿ� ����� �¸�
	*/
	int RandomNumber = rand() % 100 + 1;
	int PlayerNumber = 0;
	int CountDown = 5;

	while (CountDown > 0)
	{
		printf("1~100 ������ ���ڸ� ������ ������ : ");
		std::cin >> PlayerNumber;
	
		if (PlayerNumber < RandomNumber)
		{
			printf("�� ū ���� ������\n");
		}
		else if (PlayerNumber > RandomNumber)
		{
			printf("�� ���� ���� ������\n");
		}
		else
		{
			printf("�����Դϴ�!\nã�� ���� %d�����ϴ�.\n", RandomNumber);
			break;
		}
		CountDown--;
		printf("���� ȸ���� %d�� �Դϴ�.\n", CountDown);
	}
	if (CountDown <= 0)
	{
		printf("�����߽��ϴ�.\n");
	}
	getchar();
	getchar();


	/*
		4. ���� ������ �κ��丮�� ��Ʈ�÷��׷� ǥ���ϱ�
			������ ������ ��Ÿ���� enum�� �����
			Ư�� �������� �߰��ϰ� �����ϴ� ���� �����ֱ�
	*/
	enum Item
	{
		Key		= 1 << 0,
		Fuse	= 1 << 1,
		Book	= 1 << 2,
		Note	= 1 << 3,		
	};

	const int ItemCount = 4;
	int Inventory = 0;
	//Inventory = 0b1111;	// �׽�Ʈ �ڵ�

	int PlayerSelect = -1;

	while (PlayerSelect != 3)
	{
		printf("� ���� �ұ�� [1:�������߰�, 2:�����ۻ���, 3:����]: ");
		std::cin >> PlayerSelect;

		switch (PlayerSelect)
		{
		case 1:
		{
			printf("� �������� �߰��ұ��? [0:����, 1:ǻ��, 2:å, 3:����]: ");
			int AddItem = 0;
			std::cin >> AddItem;
			Inventory |= (1 << AddItem);
		}
		break;
		case 2:
		{
			printf("� �������� �����ұ��? [0:����, 1:ǻ��, 2:å, 3:����]: ");
			int RemoveItem = 0;
			std::cin >> RemoveItem;
			Inventory &= (~(1 << RemoveItem));
		}
		break;
		case 3:
			continue;
		default:
			// ���� ����ϱ�
			break;
		}

		printf("�κ��丮 : ");
		if ((Inventory & Key) != 0)
		{
			printf("���� ");
		}
		if ((Inventory & Fuse) != 0)
		{
			printf("ǻ�� ");
		}
		if ((Inventory & Book) != 0)
		{
			printf("å ");
		}
		if ((Inventory & Note) != 0)
		{
			printf("���� ");
		}
		printf("\n");
	}

	getchar();
	getchar();
}
