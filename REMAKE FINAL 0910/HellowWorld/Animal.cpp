#include "Animal.h"
#include <iostream>

Animal::Animal(const char* InName)
{
    Name = InName;
    std::cout << "[" << Name << "] ������ �����Ǿ����ϴ�.\n";
}

Animal::~Animal()
{
    std::cout << "[" << Name << "] ������ ��������ϴ�.\n";
}

void Animal::Move()
{
    if (Energy > 10) { Energy -= 10; std::cout << "[" << Name << "] Move (������ -10)\n"; }
    else { std::cout << "[" << Name << "] ������ ����\n"; }
}

void Animal::MakeSound()
{
    std::cout << "[" << Name << "] �Ҹ�: \"�߿�/�۸�\"\n";
}

void Animal::Eat()
{
    Energy += 20; if (Energy > 100) Energy = 100;
    std::cout << "[" << Name << "] Eat (������ +20)\n";
}

void Animal::Sleep()
{
    ++Age; Energy = 100;
    std::cout << "[" << Name << "] Sleep (���� +1, ������ Ǯ)\n";
}

void Animal::ShowInfo()
{
    std::cout << "=== Info ===\n"
        << "�̸�: " << Name << "\n"
        << "����: " << Age << "\n"
        << "������: " << Energy << "\n";
}

// �� �ݵ�� ����(Ŭ����/���ӽ����̽� �ٱ�)����, �̸� ��Ȯ�� ��ġ
void AnimalShow()
{
    Animal cat("�����");
    cat.ShowInfo();
    cat.Move();
    cat.MakeSound();
    cat.Eat();
    cat.Sleep();
    cat.ShowInfo();
}



//#include "Animal.h"
//
//void Animal::Move()
//{
//	if (Energy < 0.1f)
//	{
//		printf("[%s] : ���� ��� ������ �� �����ϴ�.\n", Name.c_str());
//	}
//	else
//	{
//		printf("[%s] : �����Դϴ�.\n", Name.c_str());
//		SetEnergy(Energy - 0.1f);
//		printf("[%s] : �������� 10% �����մϴ�.\n", Name.c_str());
//	}
//}
//
//void Animal::MakeSound()
//{
//	printf("[%s] : �Ҹ��� ���ϴ�.\n", Name.c_str());
//}
//
//void Animal::Eat()
//{
//	printf("[%s] : �Խ��ϴ�.\n", Name.c_str());
//	printf("[%s] : �������� 30% ȸ���մϴ�.\n", Name.c_str());
//	SetEnergy(Energy + 0.3f);
//}
//
//void Animal::Sleep()
//{
//	printf("[%s] : ���� ��ϴ�.\n", Name.c_str());
//	printf("[%s] : �������� 100% ȸ���մϴ�.\n", Name.c_str());
//	SetEnergy(1.0f);
//	Age++;
//	printf("[%s] : ���̰� �ѻ� �����մϴ�. %d�� �Դϴ�.\n", Name.c_str(), Age);
//}
//
//void Animal::ShowInfo()
//{
//	printf("�̸�\t: %s\n", Name.c_str());
//	printf("����\t: %d ��\n", Age);
//	printf("������\t: %.0f �ۼ�Ʈ\n", Energy * 100);
//}
