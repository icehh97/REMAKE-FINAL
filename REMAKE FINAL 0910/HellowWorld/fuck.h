#pragma once
#include "Animal.h"
class fuck : public Animal //Tiger�� Animal�� ��� ��� �޾Ҵ�) �ۺ��� �״�� ��ӹ�����~
{
public:
	void kkk(); //Wang Gu ����


public:
	// �����Ҹ��ڴ� ����� ����� �ƴ�.
	fuck() = default;
	fuck(std::string InName)
		:Animal(InName) //�θ� Ŭ������ Animal���� ������ ó���ϴ� �Ͱ� �Ȱ��� �ض�.
	{

	}
};

