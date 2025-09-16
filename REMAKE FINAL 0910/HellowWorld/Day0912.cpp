#include "Day0912.h"
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <string>

void PrintEnemy(const Enemy* pEnemy) {
    std::printf("�̸� : %s\n", pEnemy->Name.c_str());
    std::printf("����� : %.1f\n", pEnemy->Health);
    std::printf("���ݷ� : %.1f\n", pEnemy->AttackPower);
    std::printf("���� : %d Gold\n", pEnemy->DropGold);
}

void Day0912_Struct()
{
    Enemy Goblin;
    Goblin.Name = "���1ȣ";
    PrintEnemy(&Goblin);

    Enemy* pGoblin = new Enemy();
    pGoblin->Name = "���2ȣ";
    pGoblin->Health = static_cast<float>(std::rand() % 100 + 50);
    pGoblin->AttackPower = static_cast<float>(std::rand() % 10 + 5);
    pGoblin->DropGold = static_cast<int>(pGoblin->Health * pGoblin->AttackPower);
    PrintEnemy(pGoblin);
    delete pGoblin; pGoblin = nullptr;

    Enemy NamedGoblin("�ǽ� ���");
    PrintEnemy(&NamedGoblin);

    Enemy* Goblins = new Enemy[3];
    for (int i = 0; i < 3; i++) {
        Goblins[i].Name = "���" + std::to_string(i + 1) + "ȣ";
        PrintEnemy(&Goblins[i]);
    }
    delete[] Goblins; Goblins = nullptr;

    Human SH; SH.Name = "������";
    std::printf("�̸� : %s\n����� : %.1f\n���ݷ� : %.1f\n���� : %d Gold\n",
        SH.Name.c_str(), SH.Health, SH.AttackPower, SH.DropGold);

    Human boss("���� ������", 10.0f);
    std::printf("\n[Boss]\n�̸� : %s\n����� : %.1f\n���ݷ� : %.1f\n���� : %d Gold\n",
        boss.Name.c_str(), boss.Health, boss.AttackPower, boss.DropGold);

    Weapon Sword; Sword.Name = "��ö��"; Sword.Desc = "ưư�ϴ�."; Sword.AttackPower = 15.0f; Sword.Price = 200;

    Enemy g1("���1ȣ"), g2("���2ȣ");
    Enemy t1 = g1 - g2;    // -
    Enemy t2 = 2.0f * g1;  // float * Enemy
    g2 *= 1.5f;            // *=
    PrintEnemy(&t1); PrintEnemy(&t2); PrintEnemy(&g2);
}

void Day0912_OperatorOverloading()
{
    Enemy Goblin1("���1ȣ");
    Enemy Goblin2("���2ȣ");
    Enemy FusionGoblin = Goblin1 + Goblin2;
    Enemy NerfGoblin = Goblin1 - Goblin2;
    PrintEnemy(&FusionGoblin);
    PrintEnemy(&NerfGoblin);
}
