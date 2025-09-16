#pragma once                  // 헤더가 중복 포함되는 걸 한 번만 막아줌(헤더 가드). 
// #ifndef/#define 방식보다 간단. 같은 번역단위에 여러 번 include돼도 ODR 충돌 예방에 도움.

#include <string>             // std::string 사용하려면 반드시 포함.
#include <iostream>           // iostream은 여기선 직접 안 쓰지만, 선언부에서 쓸 수도 있어 포함해둔 상태.

enum class MonsterType { Genji, Hanzo, Diva, Bob };
// enum **class** 는 강한 형식(type-safe). 암시적 int 변환이 안 돼서 실수 줄임.
// -> MonsterType::Genji 처럼 네임스페이스 분리됨. (기본 enum은 전역으로 섞여 충돌 가능)

class Monster
{
public:
    Monster() = default;      // 기본 생성자. 멤버 기본값(아래 protected의 초기값)을 그대로 사용.

    // 인자 있는 생성자.
    // 주의: 문자열은 **복사 비용**이 있으니 const std::string& 처럼 참조로 받는 게 일반적이나,
    // 네 코드는 일관성 위해 inName만 참조 사용. (아래 inSkill도 참조)
    Monster(MonsterType inType,
        const std::string& inName,
        float inHealth,
        float inAttack,
        const std::string& inSkill)
        : Type(inType),       // 멤버 초기화 리스트: 생성 시점에 바로 값 채움(성능/일관성 좋음).
        Name(inName),       // 여기서 복사 1회 발생. inName을 const&로 받아서 불필요 복사 최소화.
        Health(inHealth),
        AttackPower(inAttack),
        Skill(inSkill)      // Skill도 const& → 복사 1회. (move 활용하려면 std::string&& 설계도 가능)
    {
    }

    void Attack() const;      // const 멤버 함수: "객체의 상태를 바꾸지 않겠다"는 계약. 
    // 나중에 **상수객체( const Monster )**에서도 호출 가능.

    void ShowInfo() const;    // 출력만 하므로 const 적합.

    // === Getter들 ===
    const std::string& GetName() const { return Name; }
    // 반환 타입을 const std::string& 로 주는 이유:
    // 1) 복사 방지(성능)  2) 외부에서 수정 금지(캡슐화). 
    // ※ 주의: 이 참조는 "객체가 살아있는 동안"만 유효. (포인터/참조 생명주기 중요!)

    float GetHealth() const { return Health; }
    float GetAttackPower() const { return AttackPower; }
    MonsterType GetType() const { return Type; }
    const std::string& GetSkill() const { return Skill; }

protected:
    // 접근지정자: protected → 외부는 못 만지지만, '상속받은' 자식 클래스는 접근 가능.
    //   - 실전에서 외부로부터 보호(캡슐화), 자식의 확장성 확보.
    //   - 만약 완전 은닉 원하면 private로 두고 자식도 Getter/Setter 통해 접근하게 설계.

    MonsterType Type = MonsterType::Genji; // 기본값. 기본 생성자 시에도 유효.
    std::string Name = "몬스터";          // 멤버 기본 초기화. C++11 이후 권장.
    float Health = 1000.0f;
    float AttackPower = 100.0f;
    std::string Skill = "고유스킬!!!!";    // 기본 스킬. 생성자에서 덮어쓸 수 있음.
};

// 테스트 실행용 전역 함수. main에서 한 줄로 호출하려고 분리.
// (전역함수 자체는 OOP적이지 않지만, "데모용 진입점"으로는 간결)
void TestMonster();



#include "Monster.h"
#include <cstdio>   // printf 사용. C++이라면 iostream도 가능하지만, 여기선 printf 선택.

void Monster::Attack() const
{
    // printf는 C-API라 std::string을 직접 못 찍음 → 반드시 .c_str() (const char*)로 변환.
    // 이걸 잊으면 "쓰레기 글자"가 나오는 이유: %s는 포인터를 기대하는데,
    // std::string 객체의 내부 구조 주소를 잘못 읽게 되기 때문(UB).
    printf("%s가 공격했다! 데미지: %.1f, 고유스킬 : %s\n",
        Name.c_str(), AttackPower, Skill.c_str());
}

void Monster::ShowInfo() const
{
    // enum값을 예쁜 이름으로 최소 수정으로 바꾸기 → 문자열 테이블 사용.
    static const char* MonsterTypeNames[] = { "Genji", "Hanzo", "Diva", "Bob" };
    // ↑ static 지역 배열: 함수 호출마다 다시 만들지 않음(ROM 같은 상수 테이블처럼 씀).
    //   인덱싱은 static_cast<int>(Type) 로 안전 변환.

    printf("종류: %s | 이름: %s | 체력: %.1f | 공격력: %.1f | 고유스킬: %s\n",
        MonsterTypeNames[static_cast<int>(Type)],
        Name.c_str(),
        Health,
        AttackPower,
        Skill.c_str());
}

void TestMonster()
{
    // 여기서는 **스택 객체**를 사용. (new/delete 불필요)
    // 포인터를 꼭 배워야 한다면: Monster* p = new Monster(...); delete p;
    // 하지만 RAII 원칙상 자동 수명(스택)이 안전하고 권장.

    Monster genji(MonsterType::Genji, "겐지", 150.0f, 30.0f, "용검");
    Monster hanzo(MonsterType::Hanzo, "한조", 140.0f, 28.0f, "용의 부름");
    Monster diva(MonsterType::Diva, "디바", 200.0f, 35.0f, "이것도 너프해보시지");
    Monster bob(MonsterType::Bob, "밥", 300.0f, 50.0f, "밥줘");

    // 출력과 동작 테스트: 한 줄 호출로 데모.
    genji.ShowInfo(); genji.Attack();
    hanzo.ShowInfo(); hanzo.Attack();
    diva.ShowInfo();  diva.Attack();
    bob.ShowInfo();   bob.Attack();
}

