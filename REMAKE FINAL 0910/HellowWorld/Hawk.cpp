#include "Hawk.h"

void Hawk::Move()
{
	//Animal::Move();	// �θ��� Animal�� Move �����ϱ�
	if (Energy < 0.1f)
	{
		printf("[%s] : ���� ��� ������ �� �����ϴ�.\n", Name.c_str());
	}
	else
	{
		printf("[%s] : ���ƴٴմϴ�.\n", Name.c_str());
		SetEnergy(Energy - 0.1f);
		printf("[%s] : �������� 10% �����մϴ�.\n", Name.c_str());
	}
}

void Hawk::MakeSound()
{
	Animal::MakeSound();
	printf("����!\n");
}
