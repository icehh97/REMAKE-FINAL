#include "Day0916.h"
#include "Car.h"
#include "Animal.h"
#include "Tiger.h"

//Day0916::Day0916()
//{
//	// ��ü�� ���� �� �� ȣ��
//}
//
//Day0916::~Day0916()
//{
//	// ������ ������ �� ȣ��
//}

void Day0916::ClassInstance()
{
	Car myCar = Car("��������");	// �ν��Ͻ� ����. ������� Ÿ�̹��� �Լ��� ����Ǿ��� �� �����
	myCar.Accel();

	Car* pCar = new Car("�����Ҵ�");
	pCar->HandleTurn();
	delete pCar;
	pCar = nullptr;
}

void Day0916::TestAnimal()
{
	Animal animal;
	animal.ShowInfo();
	animal.MakeSound();
	animal.Move();
	animal.Move();
	animal.Move();
	animal.ShowInfo();
	animal.Eat();
	animal.ShowInfo();
	animal.Move();
	animal.Move();
	animal.Move();
	animal.ShowInfo();
	animal.Sleep();
	animal.ShowInfo();

	int Age = animal.GetAge();
	const std::string& Name = animal.GetName();
}

void Day0916::TestTiger()
{
	Tiger tiger = Tiger("ȣ����");
	tiger.Move();
	tiger.Hunt();
	tiger.ShowInfo();

	Animal* pAnimal = new Tiger("ȣ����");
	delete pAnimal;
	pAnimal = nullptr;
}

// ���� �ǽ�
// �ٸ� ���� ������(3����)
// �ٸ� ���� ���� �Լ� �����ϱ�