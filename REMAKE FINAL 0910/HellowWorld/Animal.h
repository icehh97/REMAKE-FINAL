#pragma once
#include <string>

class Animal
{

	std::string Name;
	float Energy = 100.0f;
	float Move;
	int Age = 0;


public: //�����ϸ� public ���� , ���� ���� �Լ� ���ʿ� 
    // Energy�� �ܺο����� �б� �����̴� . �̰� GETTER�� �б� �������� �������
    inline const float GetEnergy() const { return Energy; }
	inline int GetAge() const { return Age; }
	inline float GetMove() const { return Move; }
    //�̷��� private���� �ִ� �� 

   

    Animal() = default;
    Animal(const char* InName);
    ~Animal();

    void Move();
    void MakeSound();
    void Eat();
    void Sleep();
    void ShowInfo();

private:
	inline void SetEnergy(float InEnergy) //�̰� SETTER��
		//Energy�� ������ 0.0~1.0f�̴�.
	{
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

	float Energy = 1.0f;	// 0.0f ~ 1.0f : 1.0f�� �� 100%;
};


// ���ο��� �� �濡 ���� �׽�Ʈ �Լ�
void AnimalShow();






//#pragma once
//#include <string>
//
//class Animal
//{
//public:
//	void Move();
//	void MakeSound();
//	void Eat();
//	void Sleep();
//
//	void ShowInfo();
//
//	// Getter/Setter
//	inline const std::string& GetName() const { return Name; }
//	inline const int GetAge() const { return Age; }
//
//	// Energy�� �ܺο����� �б� �����̴�.
//	inline const float GetEnergy() const { return Energy; }
//
//public:
//	Animal() = default;
//	Animal(std::string InName)
//		: Name(InName)
//	{
//	}	// ª�� ���� �Լ��� ������ �ش��� �־ �ȴ�(�ڵ� inlineó��)
//
//private:
//	inline void SetEnergy(float InEnergy)
//	{
//		// Energy�� ������ 0.0f ~ 1.0f�̴�.
//		if (InEnergy < 0)
//		{
//			Energy = 0.0f;
//		}
//		else if (InEnergy > 1.0f)
//		{
//			Energy = 1.0f;
//		}
//		else
//		{
//			Energy = InEnergy;
//		}
//	}
//
//	std::string Name = "����";
//	int Age = 0;
//	float Energy = 1.0f;	// 0.0f ~ 1.0f : 1.0f�� �� 100%;
//};
//
//
///*
//���� Ŭ���� ������
//	Name : std::string
//	Energy : float
//	Age : int
//
//	������ �����̸�(Move) �������� �Һ��Ѵ�.
//	������ �Ҹ��� ���� �� �ִ�.(MakeSound)
//	������ ������(Eat) �������� �����Ѵ�.
//	������ ���� �ڸ�(Sleep) ���̰� �����ϰ� �������� ���� ȸ���ȴ�.
//	������ ��� ������ ����� �� �ִ�.(ShowInfo)
//*/