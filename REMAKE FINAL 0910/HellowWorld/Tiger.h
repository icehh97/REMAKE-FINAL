#pragma once
#include "Animal.h"

class Tiger : public Animal	// Tiger�� Animal�� ��� ��� �޾Ҵ�.
{
public:
	void Hunt();	// ȣ���� ���� �Լ�
	virtual void Move() override;	// ȣ���̴� Animal�� Move�Լ��� �������.
	virtual void MakeSound() override;

public:
	// ������/�Ҹ��ڴ� ����� ����� �ƴϴ�.
	Tiger() = default;
	Tiger(std::string InName)
		: Animal(InName)	// �θ� Ŭ������ Animal���� ������ ó���ϴ� �Ͱ� �Ȱ��� �ض�.
	{
	}
	virtual ~Tiger() {}
};

