#pragma once
#include "ClassNPC.h"

//TODO: ��������� ��� ��������������

class NPCEnemy :public NPC
{
public:
	bool Left = false;					//�������� �����
	bool right = true;					//������� ������
	NPCEnemy() {};
};

