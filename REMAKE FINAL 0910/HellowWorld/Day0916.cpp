#include "Day0916.h"
#include "Car.h"

//Day0916::Day0916()
//{
//	// 객체가 생성 될 때 호출
//}
//
//Day0916::~Day0916()
//{
//	// 객제가 해제될 때 호출
//}

void Day0916::ClassInstance()
{
	Car myCar = Car("지역변수");	// 인스턴스 생성. 사라지는 타이밍은 함수가 종료되었을 때 사라짐

	Car* pCar = new Car("동적할당");
	delete pCar;
	pCar = nullptr;
}

void Day0916::WaangGu()
{
}


/*
동물 클래스 만들어보기
	Name : std::string
	Energy : float
	Age : int

	동물은 움직이면(Move) 에너지를 소비한다.
	동물은 소리를 지를 수 있다.(MakeSound)
	동물은 먹으면(Eat) 에너지가 증가한다.
	동물은 잠을 자면(Sleep) 나이가 증가하고 에너지가 완전 회복된다.
	동물의 모든 정보를 출력할 수 있다.(ShoInfo)
*/