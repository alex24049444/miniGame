//����������� ���� ������� ������-�������� "NPC"

#include "ClassNPC.h"

void NPC::Draw(float time)																			//������ �� ��������� NPC, ��������� �������� � ������
{
	dxN = speedNX; dyN = speedNY;										//�������� �������� ���������
	xNReal += dxN * time;												//������
	yNReal += dyN * time;												//����������� �������� ������ � ������������
	xN = xNReal - xNRealInside;											//��������� ����������� ������ � ������������
	yN = yNReal - yNRealInside;
	sprite.setPosition(xN, yN);											//��������� ����� ��������� �� ������� �N,�N
	layerN = trunc(yNReal + hNRealInside);								//��������� ������� �����, ���� ����� ���������: layerH = round(yHReal + hHRealInside);	
}

void NPC::SetRealSizeNPC(float xRealIns, float yRealIns, float wRealIns, float hRealIns) {			//���������� ����� ������� ���������� ������ NPC
	xNRealInside = xRealIns;
	yNRealInside = yRealIns;
	wNRealInside = wRealIns;
	hNRealInside = hRealIns;
}