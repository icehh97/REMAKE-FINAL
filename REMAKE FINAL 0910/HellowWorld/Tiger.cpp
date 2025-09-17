#include "Tiger.h"

void Tiger::Hunt()
{
	printf("[%s]�� ����� �մϴ�.\n", Name.c_str());
	SetEnergy(Energy - 0.5f);
	printf("[%s] : �������� 50% �����մϴ�.\n", Name.c_str());
}

void Tiger::Move()
{
	printf("[%s]�� ��ȿ�մϴ�.\n", Name.c_str());
	Animal::Move();
}

void Tiger::MakeSound()
{
	Animal::MakeSound();
	printf("����!\n");
}
