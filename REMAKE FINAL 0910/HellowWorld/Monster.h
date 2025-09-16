#pragma once
#include <string>
#include <iostream>

enum class MonsterType { Genji, Hanzo, Diva, Bob };

class Monster
{
public:
    Monster() = default;

    Monster(MonsterType inType, const std::string& inName, float inHealth, float inAttack, const std::string& inSkill)
        : Type(inType), Name(inName), Health(inHealth), AttackPower(inAttack),Skill(inSkill) {
    }

    void Attack() const;
    void ShowInfo() const;

 
    const std::string& GetName() const { return Name; }
    float GetHealth() const { return Health; }
    float GetAttackPower() const { return AttackPower; }
    MonsterType GetType() const { return Type; }
    const std::string& GetSkill() const { return Skill; }

protected:
    MonsterType Type = MonsterType::Genji;
    std::string Name = "몬스터";
    float Health = 1000.0f;
    float AttackPower = 100.0f;
    std::string Skill = "고유스킬!!!!";
}; 
void TestMonster();