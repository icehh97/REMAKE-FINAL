#include "Day0912.h"
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <string>

void PrintEnemy(const Enemy* pEnemy) {
    std::printf("이름 : %s\n", pEnemy->Name.c_str());
    std::printf("생명력 : %.1f\n", pEnemy->Health);
    std::printf("공격력 : %.1f\n", pEnemy->AttackPower);
    std::printf("보상 : %d Gold\n", pEnemy->DropGold);
}

void Day0912_Struct()
{
    Enemy Goblin;
    Goblin.Name = "고블린1호";
    PrintEnemy(&Goblin);

    Enemy* pGoblin = new Enemy();
    pGoblin->Name = "고블린2호";
    pGoblin->Health = static_cast<float>(std::rand() % 100 + 50);
    pGoblin->AttackPower = static_cast<float>(std::rand() % 10 + 5);
    pGoblin->DropGold = static_cast<int>(pGoblin->Health * pGoblin->AttackPower);
    PrintEnemy(pGoblin);
    delete pGoblin; pGoblin = nullptr;

    Enemy NamedGoblin("뽀스 고블린");
    PrintEnemy(&NamedGoblin);

    Enemy* Goblins = new Enemy[3];
    for (int i = 0; i < 3; i++) {
        Goblins[i].Name = "고블린" + std::to_string(i + 1) + "호";
        PrintEnemy(&Goblins[i]);
    }
    delete[] Goblins; Goblins = nullptr;

    Human SH; SH.Name = "조갈통";
    std::printf("이름 : %s\n생명력 : %.1f\n공격력 : %.1f\n보상 : %d Gold\n",
        SH.Name.c_str(), SH.Health, SH.AttackPower, SH.DropGold);

    Human boss("보스 조갈통", 10.0f);
    std::printf("\n[Boss]\n이름 : %s\n생명력 : %.1f\n공격력 : %.1f\n보상 : %d Gold\n",
        boss.Name.c_str(), boss.Health, boss.AttackPower, boss.DropGold);

    Weapon Sword; Sword.Name = "강철검"; Sword.Desc = "튼튼하다."; Sword.AttackPower = 15.0f; Sword.Price = 200;

    Enemy g1("고블린1호"), g2("고블린2호");
    Enemy t1 = g1 - g2;    // -
    Enemy t2 = 2.0f * g1;  // float * Enemy
    g2 *= 1.5f;            // *=
    PrintEnemy(&t1); PrintEnemy(&t2); PrintEnemy(&g2);
}

void Day0912_OperatorOverloading()
{
    Enemy Goblin1("고블린1호");
    Enemy Goblin2("고블린2호");
    Enemy FusionGoblin = Goblin1 + Goblin2;
    Enemy NerfGoblin = Goblin1 - Goblin2;
    PrintEnemy(&FusionGoblin);
    PrintEnemy(&NerfGoblin);
}
