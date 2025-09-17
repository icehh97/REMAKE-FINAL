#include "Day0917.h"
#include "Tiger.h"
#include "Hawk.h"
#include "Dog.h"
#include "TeseSample.h"

void Day0917::TestPolymorphism()
{
	Tiger* pTiger = new Tiger("ȣ����");
	Hawk* pHawk = new Hawk("����");

	printf("ȣ���� �̵�\n");
	pTiger->Move();
	printf("���� �̵�\n");
	pHawk->Move();

	printf("���� �̵�\n");
	Animal* pAnimal = pHawk;
	pAnimal->Move();	// Animal�� Move�� ����� -> �����Լ��� �� �Ŀ��� ���� Ŭ������ Move�� ����ȴ�.
	pAnimal = pTiger;
	pAnimal->Move();

	// C ��Ÿ�� ĳ����(����)
	//Tiger* pTempTiger = (Tiger*)pAnimal;
	//pTempTiger->Hunt();
	//((Tiger*)pAnimal)->Hunt();

	// C++ ��Ÿ�� ĳ���� �� �ϳ�
	// dynamic_cast : ��Ÿ��(������)�� �� �ּҰ� ���� � �ڽ� Ŭ������ ��ü�� ����Ű�� �ִ��� �����ϰ� Ȯ�����ִ� cast

	Tiger* pTempTiger = dynamic_cast<Tiger*>(pAnimal);
	if (pTempTiger == nullptr)
	{
		// pAnimal�� Tiger*�� �ƴϴ�.
	}
	else
	{
		// pAnimal�� ����� �ּҴ� Tiger�� �ּҰ� �´�.
		pTempTiger->Hunt();
	}

	// pAnimal->Hunt(); // ��� �Ұ���

	delete pTiger;
	pTiger = nullptr;

	delete pHawk;
	pHawk = nullptr;
}

void Day0917::TestVirtualFunction()
{
	Parent* pParent = new Child();	// ����
	delete pParent;
	pParent = nullptr;
}

void Day0917::TestPractice1()
{
	// ���� �ǽ�
	// Animal*�� �迭 �����
	// ���� ������ ������ �ֱ�
	// �迭�� ����ִ� ��� ������ MakeSound �����ϱ�

	Animal* Zoo[5];
	Zoo[0] = new Tiger("ȣ����");
	Zoo[1] = new Tiger("ȣ����");
	Zoo[2] = new Hawk("����");
	Zoo[3] = new Hawk("�ŵ���");
	Zoo[4] = new Dog("�۸���");

	for (int i = 0; i < 5; i++)
	{
		Zoo[i]->MakeSound();
	}

	for (int i = 0; i < 5; i++)
	{
		delete Zoo[i];
		Zoo[i] = nullptr;
	}


}


