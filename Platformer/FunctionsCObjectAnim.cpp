#include "ClassObjectAnim.h"

/*
��������� ��������:
1)��������� �����, � ������� ��������
2)�������� �������� � ������
*/

void ObjectAnim::Draw(View view)
{
	if (tracking == true) {
		sf::Vector2f vector = view.getCenter();																				//���� ������ "��������"
		spriteObject.setPosition(xR + (vector.x - xR) / trackingCoefficient, yR + (vector.y - yR) / trackingCoefficient);	//�������������� ������������� ����� ��������� ����������� �� ������ ����
	}
	else
	{
		if (animated == true || movableO == true) {																		//���� ������ ��������� ��� ������
			layer = yRReal + hRReal;
			xR = xRReal - xRRealInside;
			yR = yRReal - yRRealInside;
			spriteObject.setPosition(xR, yR);																			//���� ��������� ������ ����� ���������
		}
	}
}

