#include <stdio.h>
#include "Car.h"

Car::Car(const char* InName)
	: Name(InName)
{
	printf("[%s] �ڵ����� �����Ǿ����ϴ�.", Name.c_str());
}

Car::~Car()
{
	printf("[%s] �ڵ����� �����Ǿ����ϴ�.", Name.c_str());
}

void Car::Accel()	// CarŬ������ Accel �Լ�
{
	printf("�ڵ����� �����մϴ�.\n");
}

void Car::Brake()
{
	printf("�ڵ����� �����մϴ�.\n");
}

void Car::HandleTurn()
{
	printf("�ڵ��� �����ϴ�.\n");
}
