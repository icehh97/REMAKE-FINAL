#pragma once
#include <string>

class Animal
{
public:
	void Move();
	void MakeSound();
	void Eat();
	void Sleep();

	void ShowInfo();

	// Getter/Setter
	inline const std::string& GetName() const { return Name; }
	inline const int GetAge() const { return Age; }

	// Energy�� �ܺο����� �б� �����̴�.
	inline const float GetEnergy() const { return Energy; }

public:
	Animal() = default;
	Animal(std::string InName)
		: Name(InName)
	{
	}	// ª�� ���� �Լ��� ������ �ش��� �־ �ȴ�(�ڵ� inlineó��)

protected:
	inline void SetEnergy(float InEnergy)
	{
		// Energy�� ������ 0.0f ~ 1.0f�̴�.
		if (InEnergy < 0)
		{
			Energy = 0.0f;
		}
		else if (InEnergy > 1.0f)
		{
			Energy = 1.0f;
		}
		else
		{
			Energy = InEnergy;
		}
	}

	std::string Name = "����";
	int Age = 0;
	float Energy = 1.0f;	// 0.0f ~ 1.0f : 1.0f�� �� 100%;
};


/*
���� Ŭ���� ������
	Name : std::string
	Energy : float
	Age : int

	������ �����̸�(Move) �������� �Һ��Ѵ�.
	������ �Ҹ��� ���� �� �ִ�.(MakeSound)
	������ ������(Eat) �������� �����Ѵ�.
	������ ���� �ڸ�(Sleep) ���̰� �����ϰ� �������� ���� ȸ���ȴ�.
	������ ��� ������ ����� �� �ִ�.(ShowInfo)
*/