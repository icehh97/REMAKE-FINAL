#include "Monster.h"
#include <cstdio>

static const char* MonsterTypeName[] = { "����", "����", "��� ", "��" };

void Monster::Attack() const
{
    printf("%s�� �����ߴ�! ������: %.1f, ������ų : %s\n",
        Name.c_str(), AttackPower, Skill.c_str());
}

void Monster::ShowInfo() const
{
    printf("����: %s | �̸�: %s | ü��: %.1f | ���ݷ�: %.1f | ������ų: %s\n",
    MonsterTypeName[ static_cast<int>(Type)], Name.c_str(), Health, AttackPower, Skill.c_str());
}

void TestMonster() {
    Monster genji(MonsterType::Genji, "����", 150.0f, 30.0f, "���");
    Monster hanzo(MonsterType::Hanzo, "����", 140.0f, 28.0f, "���� �θ�");
    Monster diva(MonsterType::Diva, "���", 200.0f, 35.0f, "�̰͵� �����غ�����");
    Monster bob(MonsterType::Bob, "��", 300.0f, 50.0f, "����");

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
