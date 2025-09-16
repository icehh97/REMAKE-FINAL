#include "Animal.h"
#include <iostream>

Animal::Animal(const char* InName)
{
    Name = InName;
    std::cout << "[" << Name << "] 동물이 생성되었습니다.\n";
}

Animal::~Animal()
{
    std::cout << "[" << Name << "] 동물이 사라졌습니다.\n";
}

void Animal::Move()
{
    if (Energy > 10) { Energy -= 10; std::cout << "[" << Name << "] Move (에너지 -10)\n"; }
    else { std::cout << "[" << Name << "] 에너지 부족\n"; }
}

void Animal::MakeSound()
{
    std::cout << "[" << Name << "] 소리: \"야옹/멍멍\"\n";
}

void Animal::Eat()
{
    Energy += 20; if (Energy > 100) Energy = 100;
    std::cout << "[" << Name << "] Eat (에너지 +20)\n";
}

void Animal::Sleep()
{
    ++Age; Energy = 100;
    std::cout << "[" << Name << "] Sleep (나이 +1, 에너지 풀)\n";
}

void Animal::ShowInfo()
{
    std::cout << "=== Info ===\n"
        << "이름: " << Name << "\n"
        << "나이: " << Age << "\n"
        << "에너지: " << Energy << "\n";
}

// ★ 반드시 전역(클래스/네임스페이스 바깥)에서, 이름 정확히 일치
void AnimalShow()
{
    Animal cat("고양이");
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
//		printf("[%s] : 힘이 없어서 움직일 수 없습니다.\n", Name.c_str());
//	}
//	else
//	{
//		printf("[%s] : 움직입니다.\n", Name.c_str());
//		SetEnergy(Energy - 0.1f);
//		printf("[%s] : 에너지가 10% 감소합니다.\n", Name.c_str());
//	}
//}
//
//void Animal::MakeSound()
//{
//	printf("[%s] : 소리를 냅니다.\n", Name.c_str());
//}
//
//void Animal::Eat()
//{
//	printf("[%s] : 먹습니다.\n", Name.c_str());
//	printf("[%s] : 에너지를 30% 회복합니다.\n", Name.c_str());
//	SetEnergy(Energy + 0.3f);
//}
//
//void Animal::Sleep()
//{
//	printf("[%s] : 잠을 잡니다.\n", Name.c_str());
//	printf("[%s] : 에너지를 100% 회복합니다.\n", Name.c_str());
//	SetEnergy(1.0f);
//	Age++;
//	printf("[%s] : 나이가 한살 증가합니다. %d살 입니다.\n", Name.c_str(), Age);
//}
//
//void Animal::ShowInfo()
//{
//	printf("이름\t: %s\n", Name.c_str());
//	printf("나이\t: %d 살\n", Age);
//	printf("에너지\t: %.0f 퍼센트\n", Energy * 100);
//}
