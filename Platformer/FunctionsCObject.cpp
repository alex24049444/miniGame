#include "ClassObject.h"

/*
��������� ��� ��������� ������� ��������:
1)��������� �����, � ������� ��������
2)�������� �������� � ������
3)��������� ������� �������� �� ������� TODO: ����� ���������
*/
void Object::Draw(View view) {	//TODO: C������ ���������� �� 3 ������� ������, �������, ��������, ������������� � �� �����������: �������� ������������� � �������� �������
	if (movableO == true) {
		layer = yRReal + hRReal;
		xR = xRReal - xRRealInside;
		yR = yRReal - yRRealInside;
		spriteObject.setPosition(xR, yR);
	}
}

//��������� ������� �� ���� ��� ���������� ������������������ ���������
/*void Object::DetermineLayer()
{
	if(animated==true)
	{
		layer = yRReal + hRReal;
	}
}*/
