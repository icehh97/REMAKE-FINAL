#include "Day0916.h"
#include "Car.h"

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

	Car* pCar = new Car("�����Ҵ�");
	delete pCar;
	pCar = nullptr;
}

void Day0916::WaangGu()
{
}


/*
���� Ŭ���� ������
	Name : std::string
	Energy : float
	Age : int

	������ �����̸�(Move) �������� �Һ��Ѵ�.
	������ �Ҹ��� ���� �� �ִ�.(MakeSound)
	������ ������(Eat) �������� �����Ѵ�.
	������ ���� �ڸ�(Sleep) ���̰� �����ϰ� �������� ���� ȸ���ȴ�.
	������ ��� ������ ����� �� �ִ�.(ShoInfo)
*/