#pragma once
#include "ClassNPC.h"

//TODO: Разрешить все предупреждения

class NPCEnemy :public NPC
{
public:
	bool Left = false;					//Двмижняк влеко
	bool right = true;					//Движняк вправо
	NPCEnemy() {};
};

