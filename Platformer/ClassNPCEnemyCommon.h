#pragma once
#include "ClassNPCEnemy.h"

//TODO: Разрешить все предупреждения и сделать наследование от NPCEnemy

class NPCEnemyCommon :public NPCEnemy
{
protected:
	
	int currentAction = 0;				//Номер текущего действия в логике ЛОГИКА
	float currentActionTime = 0;		//Время выполнения текущего действие ЛОГИКА
	
	float logicReaction=0;				//Скорость реакции ЛОГИКА
	
public:
	
	NPCEnemyCommon() {};
	bool Left = false;					//Двмижняк влеко
	bool right = true;					//Движняк вправо
	bool lifeDL = false;
	int ch1 = 0;
	void Logic(float) override{};													//Логика для  NPC из треша
	void Set_currentAction(int value) { currentAction = value; };
};

