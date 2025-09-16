//
//void Day0908_MazeEscape()
//{
//	/*
//	*	- 2���� �迭�� Ȱ���Ͽ� �ؽ�Ʈ ��� �̷� Ż�� ������ ����.
//		- �̷��� ����
//			- 10�� 20���� 2���� �迭
//			- ���� ���
//				- ��(0): '. '���� ǥ��
//				- ��(1): '# '���� ǥ��
//				- ������(2): 'S '�� ǥ��
//				- �ⱸ(3): 'E '�� ǥ��
//			- �̷� �ڵ�
//
//				```cpp
//				// �̷� ũ��
//				const int MazeRows = 10;
//				const int MazeCols = 20;
//
//				// �̷� �迭
//				int Maze[MazeRows][MazeCols] =
//				{
//					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//					{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
//					{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
//					{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
//					{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
//					{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
//					{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
//					{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
//					{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
//					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//				};
//				```
//
//		- �̵� �Է� ó��
//			- w(W): ��, s(S): �Ʒ�, a(A): ����, d(D): ������
//			- ��ҹ��� ���� ���� ó��
//		- �÷��̾ �ⱸ�� �����ϸ� ����
//			- �÷��̾�� ��P ���� ǥ��
//		- ���� ȭ���� ������ ���� ����� ������.
//
//			```cpp
//			=== �ؽ�Ʈ �̷� Ż�� ���� ===
//			[�̷� ȭ�� ���]
//			�̵��� �� �ִ� ������ �����ϼ��� (w: ��, s: �Ʒ�, a: ����, d: ������):
//			w(��) s(��) a(��) d(��)
//			���� �Է�:
//			```
//	*/
//
//	int PlayerX = 0;
//	int PlayerY = 0;
//	FindStartPosition(PlayerX, PlayerY);
//
//	printf("~~ �̷� Ż�� ���� ~~\n");
//
//	while (true)
//	{
//		PrintMaze(PlayerX, PlayerY);
//
//		if (IsEnd(PlayerX, PlayerY))
//		{
//			printf("�����մϴ�! �̷θ� Ż���߽��ϴ�!\n");
//			break;
//		}
//
//		int MoveFlags = PrintAvailableMoves(PlayerX, PlayerY);
//		MoveDirection Direction = GetMoveInput(MoveFlags);
//		switch (Direction)
//		{
//		case DirUp:
//			PlayerY--;
//			break;
//		case DirDown:
//			PlayerY++;
//			break;
//		case DirLeft:
//			PlayerX--;
//			break;
//		case DirRight:
//			PlayerX++;
//			break;
//		case DirNone:
//		default:
//			// ���� �� ����
//			break;
//		}
//	}
//
//}
//
//void PrintMaze(int PlayerX, int PlayerY)
//{
//	for (int y = 0; y < MazeHeight; y++)
//	{
//		for (int x = 0; x < MazeWidth; x++)
//		{
//			if (PlayerX == x && PlayerY == y)
//			{
//				printf("P ");
//			}
//			else if (Maze[y][x] == Wall)
//			{
//				printf("# ");
//			}
//			else if (Maze[y][x] == Path)
//			{
//				printf(". ");
//			}
//			else if (Maze[y][x] == Start)
//			{
//				printf("S ");
//			}
//			else if (Maze[y][x] == End)
//			{
//				printf("E ");
//			}
//			else
//			{
//				// ���� ������ �ȵǴ� �� == �� �����Ͱ� �߸��� ��
//			}
//		}
//		printf("\n");
//	}
//}
//
//void FindStartPosition(int& OutStartX, int& OutStartY)
//{
//	for (int y = 0; y < MazeHeight; y++)
//	{
//		for (int x = 0; x < MazeWidth; x++)
//		{
//			if (Maze[y][x] == Start)
//			{
//				OutStartX = x;
//				OutStartY = y;
//				return;
//			}
//		}
//	}
//	OutStartX = 0;
//	OutStartY = 0;
//}
//
//int PrintAvailableMoves(int PlayerX, int PlayerY)
//{
//	int MoveFlags = DirNone;
//
//	printf("�̵��� �� �ִ� ������ �����ϼ��� (w:�� a:���� s:�Ʒ��� d:������):\n");
//	if (!IsWall(PlayerX, PlayerY - 1))
//	{
//		printf("W(��) ");
//		MoveFlags |= DirUp;
//	}
//	if (!IsWall(PlayerX, PlayerY + 1))
//	{
//		printf("S(��) ");
//		MoveFlags |= DirDown;
//	}
//	if (!IsWall(PlayerX - 1, PlayerY))
//	{
//		printf("A(��) ");
//		MoveFlags |= DirLeft;
//	}
//	if (!IsWall(PlayerX + 1, PlayerY))
//	{
//		printf("D(��) ");
//		MoveFlags |= DirRight;
//	}
//	printf("\n");
//
//	return MoveFlags;
//}
//
//bool IsWall(int X, int Y)
//{
//	bool isWall = false;
//	if (Y < 0 || Y >= MazeHeight ||
//		X < 0 || X >= MazeWidth ||
//		Maze[Y][X] == Wall)
//		isWall = true;
//	return isWall;
//}
//
//bool IsEnd(int X, int Y)
//{
//	return Maze[Y][X] == End;
//}
//
//MoveDirection GetMoveInput(int MoveFlags)
//{
//	char InputChar = 0;
//	MoveDirection Direction = DirNone;
//
//	while (true)
//	{
//		printf("������ �Է��ϼ��� : ");
//		std::cin >> InputChar;
//
//		if ((InputChar == 'w' || InputChar == 'W')
//			&& (MoveFlags & DirUp) /*!= 0*/)
//		{
//			Direction = DirUp;
//			break;
//		}
//		if ((InputChar == 's' || InputChar == 'S')
//			&& (MoveFlags & DirDown) /*!= 0*/)
//		{
//			Direction = DirDown;
//			break;
//		}
//		if ((InputChar == 'a' || InputChar == 'A')
//			&& (MoveFlags & DirLeft) /*!= 0*/)
//		{
//			Direction = DirLeft;
//			break;
//		}
//		if ((InputChar == 'd' || InputChar == 'D')
//			&& (MoveFlags & DirRight) /*!= 0*/)
//		{
//			Direction = DirRight;
//			break;
//		}
//
//		printf("�߸��� �Է��Դϴ�. �̵��� �� �ִ� ���� �߿��� �����ϼ���.\n");
//	}
//
//	return Direction;
//}
//
//
//
//const int WidthNewMaze = 20;
//const int HeightNewMaze = 10;
//
//const int NewMaze[HeightNewMaze][WidthNewMaze] =
//{
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
//	{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
//	{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
//	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
//	{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
//	{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
//	{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
//	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//};
//
//enum NewMaze {Path = 0, all = 1, Start = 2, End = 3  };