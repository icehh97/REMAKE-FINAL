#pragma once
#include "Animal.h"
class WangGu : public Animal //Tiger�� Animal�� ��� ��� �޾Ҵ�) �ۺ��� �״�� ��ӹ�����~
{
public:
	void Hunt(); //Wang Gu ����


public:
	// �����Ҹ��ڴ� ����� ����� �ƴ�.
	WangGu() = default;
	WangGu(std::string InName)
		:Animal(InName) //�θ� Ŭ������ Animal���� ������ ó���ϴ� �Ͱ� �Ȱ��� �ض�.
	{

	}
};

