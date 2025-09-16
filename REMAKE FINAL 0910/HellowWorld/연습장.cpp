#pragma once                  // ����� �ߺ� ���ԵǴ� �� �� ���� ������(��� ����). 
// #ifndef/#define ��ĺ��� ����. ���� ���������� ���� �� include�ŵ� ODR �浹 ���濡 ����.

#include <string>             // std::string ����Ϸ��� �ݵ�� ����.
#include <iostream>           // iostream�� ���⼱ ���� �� ������, ����ο��� �� ���� �־� �����ص� ����.

enum class MonsterType { Genji, Hanzo, Diva, Bob };
// enum **class** �� ���� ����(type-safe). �Ͻ��� int ��ȯ�� �� �ż� �Ǽ� ����.
// -> MonsterType::Genji ó�� ���ӽ����̽� �и���. (�⺻ enum�� �������� ���� �浹 ����)

class Monster
{
public:
    Monster() = default;      // �⺻ ������. ��� �⺻��(�Ʒ� protected�� �ʱⰪ)�� �״�� ���.

    // ���� �ִ� ������.
    // ����: ���ڿ��� **���� ���**�� ������ const std::string& ó�� ������ �޴� �� �Ϲ����̳�,
    // �� �ڵ�� �ϰ��� ���� inName�� ���� ���. (�Ʒ� inSkill�� ����)
    Monster(MonsterType inType,
        const std::string& inName,
        float inHealth,
        float inAttack,
        const std::string& inSkill)
        : Type(inType),       // ��� �ʱ�ȭ ����Ʈ: ���� ������ �ٷ� �� ä��(����/�ϰ��� ����).
        Name(inName),       // ���⼭ ���� 1ȸ �߻�. inName�� const&�� �޾Ƽ� ���ʿ� ���� �ּ�ȭ.
        Health(inHealth),
        AttackPower(inAttack),
        Skill(inSkill)      // Skill�� const& �� ���� 1ȸ. (move Ȱ���Ϸ��� std::string&& ���赵 ����)
    {
    }

    void Attack() const;      // const ��� �Լ�: "��ü�� ���¸� �ٲ��� �ʰڴ�"�� ���. 
    // ���߿� **�����ü( const Monster )**������ ȣ�� ����.

    void ShowInfo() const;    // ��¸� �ϹǷ� const ����.

    // === Getter�� ===
    const std::string& GetName() const { return Name; }
    // ��ȯ Ÿ���� const std::string& �� �ִ� ����:
    // 1) ���� ����(����)  2) �ܺο��� ���� ����(ĸ��ȭ). 
    // �� ����: �� ������ "��ü�� ����ִ� ����"�� ��ȿ. (������/���� �����ֱ� �߿�!)

    float GetHealth() const { return Health; }
    float GetAttackPower() const { return AttackPower; }
    MonsterType GetType() const { return Type; }
    const std::string& GetSkill() const { return Skill; }

protected:
    // ����������: protected �� �ܺδ� �� ��������, '��ӹ���' �ڽ� Ŭ������ ���� ����.
    //   - �������� �ܺηκ��� ��ȣ(ĸ��ȭ), �ڽ��� Ȯ�强 Ȯ��.
    //   - ���� ���� ���� ���ϸ� private�� �ΰ� �ڽĵ� Getter/Setter ���� �����ϰ� ����.

    MonsterType Type = MonsterType::Genji; // �⺻��. �⺻ ������ �ÿ��� ��ȿ.
    std::string Name = "����";          // ��� �⺻ �ʱ�ȭ. C++11 ���� ����.
    float Health = 1000.0f;
    float AttackPower = 100.0f;
    std::string Skill = "������ų!!!!";    // �⺻ ��ų. �����ڿ��� ��� �� ����.
};

// �׽�Ʈ ����� ���� �Լ�. main���� �� �ٷ� ȣ���Ϸ��� �и�.
// (�����Լ� ��ü�� OOP������ ������, "����� ������"���δ� ����)
void TestMonster();



#include "Monster.h"
#include <cstdio>   // printf ���. C++�̶�� iostream�� ����������, ���⼱ printf ����.

void Monster::Attack() const
{
    // printf�� C-API�� std::string�� ���� �� ���� �� �ݵ�� .c_str() (const char*)�� ��ȯ.
    // �̰� ������ "������ ����"�� ������ ����: %s�� �����͸� ����ϴµ�,
    // std::string ��ü�� ���� ���� �ּҸ� �߸� �а� �Ǳ� ����(UB).
    printf("%s�� �����ߴ�! ������: %.1f, ������ų : %s\n",
        Name.c_str(), AttackPower, Skill.c_str());
}

void Monster::ShowInfo() const
{
    // enum���� ���� �̸����� �ּ� �������� �ٲٱ� �� ���ڿ� ���̺� ���.
    static const char* MonsterTypeNames[] = { "Genji", "Hanzo", "Diva", "Bob" };
    // �� static ���� �迭: �Լ� ȣ�⸶�� �ٽ� ������ ����(ROM ���� ��� ���̺�ó�� ��).
    //   �ε����� static_cast<int>(Type) �� ���� ��ȯ.

    printf("����: %s | �̸�: %s | ü��: %.1f | ���ݷ�: %.1f | ������ų: %s\n",
        MonsterTypeNames[static_cast<int>(Type)],
        Name.c_str(),
        Health,
        AttackPower,
        Skill.c_str());
}

void TestMonster()
{
    // ���⼭�� **���� ��ü**�� ���. (new/delete ���ʿ�)
    // �����͸� �� ����� �Ѵٸ�: Monster* p = new Monster(...); delete p;
    // ������ RAII ��Ģ�� �ڵ� ����(����)�� �����ϰ� ����.

    Monster genji(MonsterType::Genji, "����", 150.0f, 30.0f, "���");
    Monster hanzo(MonsterType::Hanzo, "����", 140.0f, 28.0f, "���� �θ�");
    Monster diva(MonsterType::Diva, "���", 200.0f, 35.0f, "�̰͵� �����غ�����");
    Monster bob(MonsterType::Bob, "��", 300.0f, 50.0f, "����");

    // ��°� ���� �׽�Ʈ: �� �� ȣ��� ����.
    genji.ShowInfo(); genji.Attack();
    hanzo.ShowInfo(); hanzo.Attack();
    diva.ShowInfo();  diva.Attack();
    bob.ShowInfo();   bob.Attack();
}

