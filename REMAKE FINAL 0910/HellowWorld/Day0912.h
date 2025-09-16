#pragma once
#include <string>

// ���� ������ Ÿ�� ��������������������������������������������������
struct Position {
    int x = 0, y = 0;
    Position() = default;
    Position(int _x, int _y) : x(_x), y(_y) {}
    Position operator+(const Position& o) const { return { x + o.x, y + o.y }; }
    Position operator-(const Position& o) const { return { x - o.x, y - o.y }; }
};

struct Player { int x = 0, y = 0; int HP = 1000; int MaxHP = 1000; int Gold = 1000; };

struct Enemy {
    std::string Name = "MB";
    float Health = 10.0f;
    float AttackPower = 10.0f;
    int   DropGold = 1;

    Enemy() = default;
    explicit Enemy(std::string name) : Name(std::move(name)) {}
    Enemy(std::string name, float hp, float atk, int gold)
        : Name(std::move(name)), Health(hp), AttackPower(atk), DropGold(gold) {
    }

    Enemy operator+(const Enemy& other) const {
        return Enemy(Name + "(��ü)", Health + other.Health,
            AttackPower * 0.7f + other.AttackPower * 0.7f,
            DropGold + other.DropGold);
    }
    Enemy operator-(const Enemy& other) const {
        return Enemy(Name + "(����)", Health - other.Health * 0.5f,
            AttackPower - other.AttackPower * 0.5f,
            DropGold - static_cast<int>(other.DropGold * 0.5f));
    }
    Enemy& operator*=(float m) {
        Health *= m;
        AttackPower *= m;
        DropGold = static_cast<int>(DropGold * m);
        return *this;
    }
    friend Enemy operator*(float m, const Enemy& e) {
        Enemy r = e; r *= m; r.Name = e.Name + "(x" + std::to_string(m) + ")";
        return r;
    }
};

struct Weapon {
    std::string Name;
    std::string Desc;
    float AttackPower = 0.0f;
    int   Price = 0;
};

struct Human {
    std::string Name = "���";
    float Health = 100.0f;
    float AttackPower = 10.0f;
    int   DropGold = 100;

    Human() = default;
    explicit Human(std::string name) : Name(std::move(name)) {}
    Human(std::string name, float modifier) : Human() {
        Name = std::move(name);
        Health *= modifier;
        AttackPower *= modifier;
        DropGold = static_cast<int>(DropGold * modifier);
    }
};

// ���� �Լ� ����(����) ������������������������������������������
void Day0912_Struct();
void Day0912_OperatorOverloading();
void PrintEnemy(const Enemy* pEnemy);
