#pragma once
/*
Тут находятся функции, необходимые для подключения в FunctionsControlsCHero.cpp
*/


#include "ClassHero.h";

/*
Функция, отвечающая за правильность комбо 
hitType	- Тип удара, false-легкий, true-мощный
*/

bool ComboCaller(Hero & MainHero, bool hitType)																					
{
	bool correctExecution = false;																								//Булева функция,отвечающая за проверку правильности комбо

	if (MainHero.Get_comboHitH() == 1 && hitType == true) MainHero.Set_comboH(1);
	if (MainHero.Get_comboHitH() == 1 && hitType == false) MainHero.Set_comboH(2);												//Определение номера комбо по типу первого удара
										
	if (MainHero.Get_comboH() == 1)																								//1 комбо
	{
		if (MainHero.Get_comboHitH() == 1 && hitType == true) { correctExecution = true; }
		if (MainHero.Get_comboHitH() == 2 && hitType == false && MainHero.Get_comboTimer() > 0) { correctExecution = true; }
		if (MainHero.Get_comboHitH() == 3 && hitType == true && MainHero.Get_comboTimer() > 0) { correctExecution = true; }		//На завершающем ударе правильность выполнения = false, потому что выполнять больше нечего

		if (correctExecution == false) { MainHero.Set_comboH(0); MainHero.Set_comboHitH(0); }
	}

	if (MainHero.Get_comboH() == 2)																								//2 комбо
	{
		if (MainHero.Get_comboHitH() == 1 && hitType == false) { correctExecution = true; }
		if (MainHero.Get_comboHitH() == 2 && hitType == false && MainHero.Get_comboTimer() > 0) { correctExecution = true; }
		if (MainHero.Get_comboHitH() == 3 && hitType == false && MainHero.Get_comboTimer() > 0) { correctExecution = true; }	//На завершающем ударе правильность выполнения = false, потому что выполнять больше нечего
		if (MainHero.Get_comboHitH() == 3 && hitType == true && MainHero.Get_comboTimer() > 0) { correctExecution = true; }

		if (correctExecution == false) { MainHero.Set_comboH(0); MainHero.Set_comboHitH(0); }
	}
	if (correctExecution == true) return true;
	else return false;
}

void ReturnComboParameters(Hero& MainHero) {
	if(MainHero.Get_comboHitH()==1)MainHero.Set_comboH(0);
	MainHero.Change_comboHitH(-1);
}

bool ComboStaminaChecker(Hero& MainHero, bool hitType)																			//Отвечает за проверку расхода выносливости
{
	if (MainHero.Get_comboHitH() == 1 && MainHero.Get_comboH() == 1 && hitType == true) {
		if (MainHero.Get_staminaH() > 40) {
			return true;
		}
	}
	if (MainHero.Get_comboHitH() == 2 && MainHero.Get_comboH() == 1 && hitType == false) {
		if (MainHero.Get_staminaH() > 30) {
			return true;
		}
	}
	if (MainHero.Get_comboHitH() == 3 && MainHero.Get_comboH() == 1 && hitType == true) {
		if (MainHero.Get_staminaH() > 30) {
			return true;
		}
	}
	if (MainHero.Get_comboHitH() == 1 && MainHero.Get_comboH() == 2 && hitType == false) {
		if (MainHero.Get_staminaH() > 30) {
			return true;
		}
	}
	if (MainHero.Get_comboHitH() == 2 && MainHero.Get_comboH() == 2 && hitType == false) {
		if (MainHero.Get_staminaH() > 20) {
			return true;
		}
	}
	if (MainHero.Get_comboHitH() == 3 && MainHero.Get_comboH() == 2 && hitType == false) {
		if (MainHero.Get_staminaH() > 20) {
			return true;
		}
	}
	if (MainHero.Get_comboHitH() == 3 && MainHero.Get_comboH() == 2 && hitType == true) {
		if (MainHero.Get_staminaH() > 40) {
			return true;
		}
	}

	return false;
}

	void ComboStamina(Hero & MainHero, bool hitType)																				//Отвечает за расход выносливости
	{
		if (MainHero.Get_comboHitH() == 1 && MainHero.Get_comboH() == 1 && hitType == true) {
			if (MainHero.Get_staminaH() > 40)
				MainHero.Set_staminaH(MainHero.Get_staminaH() - 40);
		}
		if (MainHero.Get_comboHitH() == 2 && MainHero.Get_comboH() == 1 && hitType == false) {
			if (MainHero.Get_staminaH() > 30)
				MainHero.Set_staminaH(MainHero.Get_staminaH() - 30);
		}
		if (MainHero.Get_comboHitH() == 3 && MainHero.Get_comboH() == 1 && hitType == true) {
			if (MainHero.Get_staminaH() > 30)
				MainHero.Set_staminaH(MainHero.Get_staminaH() - 30);
		}
		if (MainHero.Get_comboHitH() == 1 && MainHero.Get_comboH() == 2 && hitType == false) {
			if (MainHero.Get_staminaH() > 30)
				MainHero.Set_staminaH(MainHero.Get_staminaH() - 30);
		}
		if (MainHero.Get_comboHitH() == 2 && MainHero.Get_comboH() == 2 && hitType == false) {
			if (MainHero.Get_staminaH() > 20)
				MainHero.Set_staminaH(MainHero.Get_staminaH() - 20);
		}
		if (MainHero.Get_comboHitH() == 3 && MainHero.Get_comboH() == 2 && hitType == false) {
			if (MainHero.Get_staminaH() > 20)
				MainHero.Set_staminaH(MainHero.Get_staminaH() - 20);
		}
		if (MainHero.Get_comboHitH() == 3 && MainHero.Get_comboH() == 2 && hitType == true) {
			if (MainHero.Get_staminaH() > 40)
				MainHero.Set_staminaH(MainHero.Get_staminaH() - 40);
		}
	}
	
void StaminaRest(Hero& MainHero, float& time, float limiter) {															//Восстановление запаса выносливости
	if (time > limiter) {
		if (MainHero.Get_staminaH() < MainHero.Get_staminaMaxH()) 
		{
			MainHero.Set_staminaH(MainHero.Get_staminaH() + 1);
			time = 0;
		}
	}
}