#include "Tiger.h"

void Tiger::Hunt()
{
	printf("[%s]�� ����� �մϴ�.\n", Name.c_str());
	SetEnergy(Energy - 0.5f);
	printf("[%s] : �������� 50% �����մϴ�.\n", Name.c_str());
}
