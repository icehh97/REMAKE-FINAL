#include "Practice_0905.h"
#include <iostream>
#include <stdio.h>
#include <random>


void Practice0905_01_05()
{
	// ���ø� �Լ��� Clamp �Լ� �����ϱ�

	int Value = -120;
	int Min = 10;
	int Max = 50;
	Value = Clamp(Value, Min, Max);

	float ValueF = 5.0f;
	float MinF = 10.0f;
	float MaxF = 50.0f;
	ValueF = Clamp(ValueF, MinF, MaxF);

	Clamp(10.0, 50.0, 90.0);

}

void Practice0905_02_05()
{
	/*
	���� �ݾ� 10000
	���ǿ� ������ �ּ� 100 �����ؾ� ��. ���� �����ݾ��� 100 ������ ��� ���� ����.
	������ A~K������ Ʈ���� ī�� �� 2���� �ߺ����� �����ϰ� ��Ŀ ī�尡 �߰��ȴ�.
	�÷��̾�� ������ ī�� �� ������ �����Ѵ�.
	���� �÷��̾ ��Ŀ�� ���ִٸ� �÷��̾��� �¸�. ���� �ݾ��� 2�踦 �޴´�.
	�÷��̾ ��Ŀ�� ���� ���ߴٸ� ���� ������ �����ϰų� ���� �ݾ��� 2�踦 �߰��� �����ϰ� �ѹ� �� ������ �� �ִ�.
	*/

	enum Card
	{
		CardA = 0,
		Card2,
		Card3,
		Card4,
		Card5,
		Card6,
		Card7,
		Card8,
		Card9,
		Card10,
		CardJ,
		CardQ,
		CardK,
		CardJoker,
		NumOfCards
	};

	int Money = 10000;
	const int MinimumBet = 100;

	while (Money >= MinimumBet)
	{
		int CurrentBet = MinimumBet;
		
		printf("������ ���ּ��� (100~%d) : ", Money);
		std::cin >> CurrentBet;
		printf("%d���� �����߽��ϴ�.\n", CurrentBet);

		Money -= CurrentBet;

		// ������ ���ϰ� �ִ�.

		int Dealer1 = rand() % CardJoker;
		int Dealer2 = -1;
		do
		{
			Dealer2 = rand() % CardJoker;
		} while (Dealer2 == Dealer1);
		int Dealer3 = -1;
		do
		{
			Dealer3 = rand() % CardJoker;
		} while (Dealer3 == Dealer1 || Dealer3 == Dealer2);

		int JokerIndex = rand() % 3;
		switch (JokerIndex)
		{
		case 0:
			Dealer1 = CardJoker;
			break;
		case 1:
			Dealer2 = CardJoker;
			break;
		case 2:
			Dealer3 = CardJoker;
			break;
		default:
			// ���� ������ �ȵȴ�.
			break;
		}

		printf("ī�带 �����ϼ��� (0, 1, 2) : ");
		int PlayerInput = 0;
		std::cin >> PlayerInput;

		bool PlayerWin = false;
		printf("�÷��̾�� %d�� �����߽��ϴ�.\n", PlayerInput);
		switch (PlayerInput)
		{
		case 0:
			if (Dealer1 == CardJoker)
			{
				// �߰���
				PlayerWin = true;
			}
			break;
		case 1:
			if (Dealer2 == CardJoker)
			{
				// �߰���
				PlayerWin = true;
			}
			break;
		case 2:
			if (Dealer3 == CardJoker)
			{
				// �߰���
				PlayerWin = true;
			}
			break;
		default:
			// ���� ������ �ȵȴ�.
			break;
		}

		if (PlayerWin)
		{
			Money += CurrentBet * 2;
			printf("��Ŀ�� �̾ҽ��ϴ�. ����� ���� �ݾ��� %d�Դϴ�.\n", Money);
		}
		else
		{
			printf("����� ���� ī��� ��Ŀ�� �ƴմϴ�.\n");

			if (Money >= CurrentBet * 2)
			{
				printf("�߰� ���� �Ͻðڽ��ϱ� ? (0:yes, 1 : no) : ");
				int Select = -1;
				std::cin >> Select;
				if (Select == 0)
				{
					Money -= CurrentBet * 2;
					CurrentBet *= 3;
					int PlayerSecondInput = -1;
					switch (PlayerInput)
					{
					case 0:
					{
						do
						{
							printf("���� ī�� �� �ϳ��� �����ϼ��� (1,2) : ");
							std::cin >> PlayerSecondInput;
						} //while (!(PlayerSecondInput == 1 || PlayerSecondInput == 2));
						while (PlayerSecondInput != 1 && PlayerSecondInput != 2);
					}
					break;
					case 1:
					{
						do
						{
							printf("���� ī�� �� �ϳ��� �����ϼ��� (0,2) : ");
							std::cin >> PlayerSecondInput;
						} while (PlayerSecondInput != 0 && PlayerSecondInput != 2);
					}
					break;
					case 2:
					{
						do
						{
							printf("���� ī�� �� �ϳ��� �����ϼ��� (0,1) : ");
							std::cin >> PlayerSecondInput;
						} while (PlayerSecondInput != 0 && PlayerSecondInput != 1);
					}
					break;
					default:
						// ���� ������ �ȵȴ�.
						break;
					}

					printf("�÷��̾�� �ι�°�� %d�� �����߽��ϴ�.\n", PlayerSecondInput);
					switch (PlayerSecondInput)
					{
					case 0:
						if (Dealer1 == CardJoker)
						{
							// �߰���
							PlayerWin = true;
						}
						break;
					case 1:
						if (Dealer2 == CardJoker)
						{
							// �߰���
							PlayerWin = true;
						}
						break;
					case 2:
						if (Dealer3 == CardJoker)
						{
							// �߰���
							PlayerWin = true;
						}
						break;
					default:
						// ���� ������ �ȵȴ�.
						break;
					}

					if (PlayerWin)
					{
						Money += CurrentBet * 2;
						printf("��Ŀ�� �̾ҽ��ϴ�. ����� ���� �ݾ��� %d�Դϴ�.\n", Money);
					}
					else
					{
						printf("����� �й��Դϴ�.\n");
					}
				}
				else
				{
					printf("����� �й��Դϴ�.\n");
				}
			}
			else
			{
				printf("����� �й��Դϴ�.\n");
			}			
		}
	}
}
