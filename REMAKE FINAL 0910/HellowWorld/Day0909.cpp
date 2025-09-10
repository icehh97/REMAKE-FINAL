#include "Day0909.h"
#include <iostream>
#include <stdio.h>
#include "Day0908.h"

void PointerParameter(int* pNumber)
{
	(*pNumber) = (*pNumber) * 2;	// �Է¹��� �ּҿ� �ִ� int���� 2��� �����
}

void TestPointer(int* pInt, float pFloat)
{
	(*pInt) += 3;
	//(pFloat) /= 2;
	(pFloat) *= 0.5f;	// *�� / �߿� ������ �� �� �ִ� ��Ȳ�̸� *�� ���ɻ� �����ϴ�.
}

void Day0909()
{
	// ���� �ǽ�
	// Number��� ������ �ϳ� �����ϰ� ������ ���� p�� Number�� �ּҸ� �����ϱ�
	// p�� �̿��ؼ� Number�� ���� �����Ű��

	float Number = 123.01f;
	int Number2 = 10;
	float* p = nullptr;	// p�� ������ ����ִ�.
	p = &Number;		// p�� Number�� �ּҸ� �����ߴ�.
	//p = &Number2;		// Ÿ���� �ٸ��� ������ �ȵȴ�.

	(*p) = 100.0f;

	PointerParameter(&Number2);

	// ���� �ǽ�
	// int*�� float*�� �Ķ���ͷ� ���� �Լ� �����
	// int*�� ���� ���� 3 ���ϱ�, float*�� ���� ���� �������� �����

	float* test = p;
	test++;

	//(*test) = 20;	// �ſ� ����. ���� �ϸ� �ȵ�. ������ ����.

	int i = 0;
}

void Day0909_ArrayAndPointer()
{
	// �迭�� ������(�⺻������ ����.)
	int Array[5] = { 10, 20, 30, 40, 50 };
	int* pArray = Array;	// �迭�� �̸��� �迭�� ù��° ����� �ּҿ� ����.
	int* pArray2 = &Array[0];	// Array == &Array[0] �ΰ��� ���� �ǹ�

	// pArray�� �̿��ؼ� Array[2]�� 300���� �����ϱ�
	*(pArray + 2) = 300;

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\n");

	for (int data : Array)		// range-for : Array���� ��ҵ��� ���������� �ϳ��� data�� �־� ó��
	{
		printf("%d ", data);
	}
	printf("\n");
		
}

void Day0909_DynamicAllocation()
{
	// C ��Ÿ�� �޸� �Ҵ� �� ����
	int Size = 5;
	int* Array = nullptr;
	Array = (int*)malloc(sizeof(int) * Size);	// int 5��¥�� �޸� �� �Ҵ� �ޱ�

	Array[2] = 20;
	/*
	�۾���
	*/

	free(Array);		// Array�� ����. malloc�� ������ ������ free���� ����� �۾��Ұ�
	Array = nullptr;	// ��۸� ������ ����

	// C++ ��Ÿ�� �޸� �Ҵ� �� ����
	int* Data = new int(5);		// int �ϳ��� �Ҵ� �޴µ� �ּҰ� ����Ű�� ���� 5�� �����ض�
	delete Data;
	Data = nullptr;
	Array = new int[10];	// int 10��¥�� �迭�� ������
	delete[] Array;				// �迭�� �ݵ�� �̷��� �����ؾ� �Ѵ�.
	//delete Array;				// ���� �̷��� �ϸ� �ȵȴ�. �̷��� �ϸ� Array[0]�κи� �Ҵ� ������ �ȴ�.
	Array = nullptr;

	
}

void Day0909_Example()
{
	// ���� �ǽ�
	// 1. int �迭 �Ҵ�ޱ�(ù �Ҵ��� 3����)
	// 2. ���ڸ� �Է¹��� ������ �迭�� �߰��ϱ�

	const int ExitInput = -1;	// �Է� ���ᰪ or ��ĭ ǥ����
	const int StartSize = 3;

	int* Array = new int[StartSize];
	for (int i = 0; i < StartSize; i++)
	{
		Array[i] = ExitInput;
	}
	int CurrentIndex = 0;
	int CurrentSize = StartSize;

	int InputNumber = 0;
	while (InputNumber != ExitInput)
	{
		printf("�迭�� ���� ���ڸ� �Է��ϼ��� : ");
		std::cin >> InputNumber;

		Array[CurrentIndex] = InputNumber;
		CurrentIndex++;

		if (CurrentIndex >= CurrentSize)
		{
			int* newArray = new int[CurrentSize + 1];
			for (int i = 0; i < CurrentSize; i++)
			{
				newArray[i] = Array[i];
			}
			newArray[CurrentSize] = ExitInput;
			delete[] Array;
			Array = newArray;
			CurrentSize++;
		}

		printf("�Էµ� ������ : ");
		for (int i=0;i<CurrentSize;i++)
		{
			printf("%d ", Array[i]);
		}
		printf("\n");
	}

	delete[] Array;
	Array = nullptr;

}

int RollDice(int FaceNumber)
{
	return rand() % FaceNumber + 1;
}

void Day0908_Practice1()
{
	//6��ü �ֻ����� 100���� ������ �� ���� ���� ��� ���Դ��� ī�����ϱ�
	//6��ü �ֻ����� ������ �Լ� �����
	printf("\n\n\n\n\n\n\n\n\n\n");
	const int TestCount = 1000000;
	int Counters[6] = { 0 };
	for (int i = 0; i < TestCount; i++)
	{
		Counters[RollDice()-1]++;
	}
	printf("���� ��� : ");
	for (auto count : Counters)
	{
		printf("%d ", count);
	}
	printf("\n");

}

void Reverse(int* Array, int Size)
{
	int HalfSize = Size / 2;
	for (int i = 0; i < HalfSize; i++)
	{
		int temp = Array[i];
		Array[i] = Array[Size - 1 - i];
		Array[Size - 1 - i] = temp;
	}

}

void Day0908_Practice2()
{
	//�迭�� ����� ���� �Ųٷ� ������ �Լ� �����
	//�Ķ���� int Array[], int Size
	int Array[10] = { 1,2,3,4,5,6,7,8,9,0 };

	printf("Array : ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\n");
	Reverse(Array, 10);
	printf("Array(Reverse) : ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\n");
}

void Day0908_Practice3()
{
	/*
	* �ζ� ��ȣ ������
	- ��ü ���� ����: 1������ 45������.
	- ����� �ϴ� ���� ����: 6��.
	*/
	const int MaxNumber = 45;
	int Array[MaxNumber];
	for (int i = 0; i < MaxNumber; i++)
	{
		Array[i] = i + 1;
	}

	Shuffle(Array, MaxNumber);

	printf("�ζ� ��ȣ�� ");
	const int PickCount = 6;
	for (int i = 0; i < PickCount; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("�Դϴ�.\n");
}

void Day0908_MazeEscape()
{
	/*
	*	- 2���� �迭�� Ȱ���Ͽ� �ؽ�Ʈ ��� �̷� Ż�� ������ ����.
		- �̷��� ����
			- 10�� 20���� 2���� �迭
			- ���� ���
				- ��(0): '. '���� ǥ��
				- ��(1): '# '���� ǥ��
				- ������(2): 'S '�� ǥ��
				- �ⱸ(3): 'E '�� ǥ��
			- �̷� �ڵ�
        
				```cpp
				// �̷� ũ��
				const int MazeRows = 10;
				const int MazeCols = 20;
        
				// �̷� �迭
				int Maze[MazeRows][MazeCols] = 
				{
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
					{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
					{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
					{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
					{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
					{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
					{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
					{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
				};
				```
        
		- �̵� �Է� ó��
			- w(W): ��, s(S): �Ʒ�, a(A): ����, d(D): ������
			- ��ҹ��� ���� ���� ó��
		- �÷��̾ �ⱸ�� �����ϸ� ����
			- �÷��̾�� ��P ���� ǥ��
		- ���� ȭ���� ������ ���� ����� ������.
    
			```cpp
			=== �ؽ�Ʈ �̷� Ż�� ���� ===
			[�̷� ȭ�� ���]
			�̵��� �� �ִ� ������ �����ϼ��� (w: ��, s: �Ʒ�, a: ����, d: ������):
			w(��) s(��) a(��) d(��)
			���� �Է�: 
			```
	*/

	int PlayerX = 0;
	int PlayerY = 0;
	FindStartPosition(PlayerX, PlayerY);

	printf("~~ �̷� Ż�� ���� ~~\n");

	while (true)
	{
		PrintMaze(PlayerX, PlayerY);

		if (IsEnd(PlayerX, PlayerY))
		{
			printf("�����մϴ�! �̷θ� Ż���߽��ϴ�!\n");
			break;
		}

		int MoveFlags = PrintAvailableMoves(PlayerX, PlayerY);
		MoveDirection Direction = GetMoveInput(MoveFlags);
		switch (Direction)
		{
		case DirUp:
			PlayerY--;
			break;
		case DirDown:
			PlayerY++;
			break;
		case DirLeft:
			PlayerX--;
			break;
		case DirRight:
			PlayerX++;
			break;
		case DirNone:
		default:
			// ���� �� ����
			break;
		}
	}

}

void PrintMaze(int PlayerX, int PlayerY)
{
	for (int y = 0; y < MazeHeight; y++)
	{
		for (int x = 0; x < MazeWidth; x++)
		{
			if (PlayerX == x && PlayerY == y)
			{
				printf("P ");
			}
			else if (Maze[y][x] == Wall)
			{
				printf("# ");
			}
			else if (Maze[y][x] == Path)
			{
				printf(". ");
			}
			else if (Maze[y][x] == Start)
			{
				printf("S ");
			}
			else if (Maze[y][x] == End)
			{
				printf("E ");
			}
			else
			{
				// ���� ������ �ȵǴ� �� == �� �����Ͱ� �߸��� ��
			}
		}
		printf("\n");
	}
}

void FindStartPosition(int& OutStartX, int& OutStartY)
{
	for (int y = 0; y < MazeHeight; y++)
	{
		for (int x = 0; x < MazeWidth; x++)
		{
			if (Maze[y][x] == Start)
			{
				OutStartX = x;
				OutStartY = y;
				return;
			}
		}
	}
	OutStartX = 0;
	OutStartY = 0;
}

int PrintAvailableMoves(int PlayerX, int PlayerY)
{
	int MoveFlags = DirNone;

	printf("�̵��� �� �ִ� ������ �����ϼ��� (w:�� a:���� s:�Ʒ��� d:������):\n");
	if (!IsWall(PlayerX, PlayerY - 1))
	{
		printf("W(��) ");
		MoveFlags |= DirUp;
	}
	if (!IsWall(PlayerX, PlayerY + 1))
	{
		printf("S(��) ");
		MoveFlags |= DirDown;
	}
	if (!IsWall(PlayerX - 1, PlayerY))
	{
		printf("A(��) ");
		MoveFlags |= DirLeft;
	}
	if (!IsWall(PlayerX + 1, PlayerY))
	{
		printf("D(��) ");
		MoveFlags |= DirRight;
	}
	printf("\n");

	return MoveFlags;
}

bool IsWall(int X, int Y)
{
	bool isWall = false;
	if (Y < 0 || Y >= MazeHeight ||
		X < 0 || X >= MazeWidth ||
		Maze[Y][X] == Wall)
		isWall = true;
	return isWall;
}

bool IsEnd(int X, int Y)
{
	return Maze[Y][X] == End;
}

MoveDirection GetMoveInput(int MoveFlags)
{
	char InputChar = 0;
	MoveDirection Direction = DirNone;

	while (true)
	{
		printf("������ �Է��ϼ��� : ");
		std::cin >> InputChar;

		if ((InputChar == 'w' || InputChar == 'W')
			&& (MoveFlags & DirUp) /*!= 0*/)
		{
			Direction = DirUp;
			break;
		}
		if ((InputChar == 's' || InputChar == 'S')
			&& (MoveFlags & DirDown) /*!= 0*/)
		{
			Direction = DirDown;
			break;
		}
		if ((InputChar == 'a' || InputChar == 'A')
			&& (MoveFlags & DirLeft) /*!= 0*/)
		{
			Direction = DirLeft;
			break;
		}
		if ((InputChar == 'd' || InputChar == 'D')
			&& (MoveFlags & DirRight) /*!= 0*/)
		{
			Direction = DirRight;
			break;
		}

		printf("�߸��� �Է��Դϴ�. �̵��� �� �ִ� ���� �߿��� �����ϼ���.\n");
	}

	return Direction;
}
