#pragma once

#include "ClassNPC.h"

using namespace sf;
//����� ���������� � ���� �������������� NPC
//����������� ������ �������� �� ��������� � ������� � ���
class NPCFriendly : public NPC 
{
protected:
	int currentAction = 0;				//����� �������� �������� � ������ ������
	float currentActionTime = 0;		//����� ���������� �������� �������� ������

	float logicReaction = 0;				//�������� ������� ������
public:
	NPCFriendly() {};
	//void Logic(float) override {};		//������ ��� �������� NPC
	void Set_currentAction(int value) { currentAction = value; };
};