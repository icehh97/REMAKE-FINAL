//
//void Day0908_MazeEscape()
//{
//	/*
//	*	- 2차원 배열을 활용하여 텍스트 기반 미로 탈출 게임을 구현.
//		- 미로의 구성
//			- 10행 20열의 2차원 배열
//			- 저장 방식
//				- 길(0): '. '으로 표시
//				- 벽(1): '# '으로 표시
//				- 시작점(2): 'S '로 표시
//				- 출구(3): 'E '로 표시
//			- 미로 코드
//
//				```cpp
//				// 미로 크기
//				const int MazeRows = 10;
//				const int MazeCols = 20;
//
//				// 미로 배열
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
//		- 이동 입력 처리
//			- w(W): 위, s(S): 아래, a(A): 왼쪽, d(D): 오른쪽
//			- 대소문자 구분 없이 처리
//		- 플레이어가 출구에 도착하면 종료
//			- 플레이어는 ‘P ‘로 표시
//		- 게임 화면은 다음과 같은 양식을 따른다.
//
//			```cpp
//			=== 텍스트 미로 탈출 게임 ===
//			[미로 화면 출력]
//			이동할 수 있는 방향을 선택하세요 (w: 위, s: 아래, a: 왼쪽, d: 오른쪽):
//			w(↑) s(↓) a(←) d(→)
//			방향 입력:
//			```
//	*/
//
//	int PlayerX = 0;
//	int PlayerY = 0;
//	FindStartPosition(PlayerX, PlayerY);
//
//	printf("~~ 미로 탈출 게임 ~~\n");
//
//	while (true)
//	{
//		PrintMaze(PlayerX, PlayerY);
//
//		if (IsEnd(PlayerX, PlayerY))
//		{
//			printf("축하합니다! 미로를 탈출했습니다!\n");
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
//			// 있을 수 없음
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
//				// 절대 들어오면 안되는 곳 == 맵 데이터가 잘못된 것
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
//	printf("이동할 수 있는 방향을 선택하세요 (w:위 a:왼쪽 s:아래쪽 d:오른쪽):\n");
//	if (!IsWall(PlayerX, PlayerY - 1))
//	{
//		printf("W(↑) ");
//		MoveFlags |= DirUp;
//	}
//	if (!IsWall(PlayerX, PlayerY + 1))
//	{
//		printf("S(↓) ");
//		MoveFlags |= DirDown;
//	}
//	if (!IsWall(PlayerX - 1, PlayerY))
//	{
//		printf("A(←) ");
//		MoveFlags |= DirLeft;
//	}
//	if (!IsWall(PlayerX + 1, PlayerY))
//	{
//		printf("D(→) ");
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
//		printf("방향을 입력하세요 : ");
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
//		printf("잘못된 입력입니다. 이동할 수 있는 방향 중에서 선택하세요.\n");
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