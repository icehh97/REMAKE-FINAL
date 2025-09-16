#include "Monster.h"
#include <cstdio>

static const char* MonsterTypeName[] = { "겐지", "한조", "디바 ", "밥" };

void Monster::Attack() const
{
    printf("%s가 공격했다! 데미지: %.1f, 고유스킬 : %s\n",
        Name.c_str(), AttackPower, Skill.c_str());
}

void Monster::ShowInfo() const
{
    printf("종류: %s | 이름: %s | 체력: %.1f | 공격력: %.1f | 고유스킬: %s\n",
    MonsterTypeName[ static_cast<int>(Type)], Name.c_str(), Health, AttackPower, Skill.c_str());
}

void TestMonster() {
    Monster genji(MonsterType::Genji, "겐지", 150.0f, 30.0f, "용검");
    Monster hanzo(MonsterType::Hanzo, "한조", 140.0f, 28.0f, "용의 부름");
    Monster diva(MonsterType::Diva, "디바", 200.0f, 35.0f, "이것도 너프해보시지");
    Monster bob(MonsterType::Bob, "밥", 300.0f, 50.0f, "밥줘");

    genji.ShowInfo();
    printf("\n");
    genji.Attack();

    hanzo.ShowInfo();
    printf("\n");
    hanzo.Attack();

    diva.ShowInfo();
    printf("\n"); ,
    diva.Attack();

    bob.ShowInfo();
    printf("\n");
    bob.Attack();
    printf("\n");
}
