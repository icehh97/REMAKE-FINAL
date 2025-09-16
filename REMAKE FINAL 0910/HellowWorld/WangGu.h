#pragma once
#include "Animal.h"
class WangGu : public Animal //Tiger는 Animal을 모두 상속 받았다) 퍼블릭은 그대로 상속받은겨~
{
public:
	void Hunt(); //Wang Gu 전용


public:
	// 생성소멸자는 상속의 대상이 아님.
	WangGu() = default;
	WangGu(std::string InName)
		:Animal(InName) //부모 클래스인 Animal에서 생성자 처리하는 것과 똑같이 해라.
	{

	}
};

