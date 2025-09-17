#pragma once
class Shape
{
public:
	virtual void Draw() = 0;	// 순수 가상 함수
	void Move();
};

