#include "MainFunctions.h";
#include "OptimizedControlsCHero.h"

/*
Тут происходит описание управления персонажем
Все условия построены по одному принципу
(Какие основыне клавиши нажаты: W/A/S/D)
{
	Булевские переменные для корректного управления
	if(Ускорение Shift)
	if(Шаг LAlt)
	if(Присед С)
	if(Прыжок Space)
	else Ничего из верхнего (Просто бег)
*/


void ControlsMainCharacter(Hero & MainHero, float time,float &stime) {

	if (MainHero.Get_battleMode() == true) {																	//Боевой мод
		MainHero.Set_buttonIsPressed(false);
		MainHero.Set_moveOnlyRight(true);
		MainHero.Set_moveOnlyLeft(true);
		MainHero.Set_onlyOneAnimation(true);
		MainHero.Set_onlyOneAnimationOneDir(true);

		if (MainHero.Get_battleModeAvaible() == true) {															//Переключение на мирный мод
			if (MainHero.Get_previousDirectionMove() == false) {
				MainHero.HeroChangeModToCivilRight(time);
			}
			if (MainHero.Get_previousDirectionMove() == true) {
				MainHero.HeroChangeModToCivilLeft(time);
			}
		}

		if (MainHero.Get_hitAviableHeavy() == true) {								//Если можно нанести тяжелый удар
			if (MainHero.Get_previousDirectionMove() == false) {
				MainHero.HeavyBlowRight(time);
				
			}
			if (MainHero.Get_previousDirectionMove() == true) {
				MainHero.HeavyBlowLeft(time);
			}
		}
		if (MainHero.Get_hitAviableLight() == true) {															//Если можно нанести легкий удар
			if (MainHero.Get_previousDirectionMove() == false) {		
				MainHero.LightBlowRight(time);
			}
			if (MainHero.Get_previousDirectionMove() == true) {
				MainHero.LightBlowLeft(time);
			}
		}

		if (MainHero.Get_battleModeAvaible() == true || MainHero.Get_hitAviableHeavy() == true || MainHero.Get_hitAviableLight() == true) MainHero.Set_controlAviable(false);
		else MainHero.Set_controlAviable(true);

		if (MainHero.Get_controlAviable() == true) 																//Если управление с клавиатуры доступно
		{														
			if (MainHero.Get_battleMode() == false) goto BattleIdleAnimation;

			if (Keyboard::isKeyPressed(Keyboard::Z) && MainHero.Get_onlyOneAnimation() == true)					//Команда переключения в мирный мод
			{
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_onlyOneAnimation(false);
				MainHero.Set_battleModeAvaible(true);
			}

			StaminaRest(MainHero, stime, 30);															//Восстановление выносливости
			if (MainHero.Get_comboTimer() > 0)MainHero.Change_comboTimer(-time);						//Если не бьем,то comboTimer уменьшается

			if (Mouse::isButtonPressed(Mouse::Right) && MainHero.Get_onlyOneAnimation() == true)		//Мощная атака, правая кнопка мыши
			{
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_onlyOneAnimation(false);	

				MainHero.Change_comboHitH(1);
				if (ComboCaller(MainHero, true) == true) MainHero.Set_hitAviableHeavy(true);
				if (ComboCaller(MainHero, true) == true) MainHero.Set_hitAviableHeavy(true);
				if (ComboStaminaChecker(MainHero, true) == false) { 
					//MainHero.Change_comboHitH(-1);
					MainHero.Set_hitAviableHeavy(false); 
				}
				else {
					ComboStamina(MainHero,true);														//Тратим выносливость
				}
			}

			if (Mouse::isButtonPressed(Mouse::Left) && MainHero.Get_onlyOneAnimation() == true)			//Легкая атака, левая кнопка мыши
			{
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_onlyOneAnimation(false);	

				MainHero.Change_comboHitH(1);
				if (ComboCaller(MainHero, false) == true) MainHero.Set_hitAviableLight(true);
				if (ComboCaller(MainHero, false) == true) MainHero.Set_hitAviableLight(true);
				if (ComboStaminaChecker(MainHero, false) == false) {
					//MainHero.Change_comboHitH(-1);
					MainHero.Set_hitAviableLight(false);
				}
				else {
					ComboStamina(MainHero,false);														//Тратим выносливость
				}
			}


			if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::S) && MainHero.Get_onlyOneAnimation() == true)	//Движение вправо/вниз
			{
				MainHero.Set_moveOnlyRight(false);
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(false);
				MainHero.Set_onlyOneAnimation(false);

				MainHero.HeroMoveRightDown(time);
			}

			if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::W) && MainHero.Get_onlyOneAnimation() == true)	//Движение вправо/вверх
			{
				MainHero.Set_moveOnlyRight(false);
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(false);
				MainHero.Set_onlyOneAnimation(false);

				MainHero.HeroMoveRightUp(time);
			}

			if (Keyboard::isKeyPressed(Keyboard::D) && MainHero.Get_moveOnlyRight() == true && MainHero.Get_onlyOneAnimation() == true)	//Движение вправо
			{
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(false);
				MainHero.Set_onlyOneAnimation(false);

				MainHero.HeroMoveRight(time);
			}

			if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::S) && MainHero.Get_onlyOneAnimation() == true)	//Движение влево/вниз
			{
				MainHero.Set_moveOnlyLeft(false);
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(true);
				MainHero.Set_onlyOneAnimation(false);

				MainHero.HeroMoveLeftDown(time);
			}

			if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::W) && MainHero.Get_onlyOneAnimation() == true)	//Движение влево/вверх
			{
				MainHero.Set_moveOnlyLeft(false);
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(true);
				MainHero.Set_onlyOneAnimation(false);

				MainHero.HeroMoveLeftUp(time);
			}

			if (Keyboard::isKeyPressed(Keyboard::A) && MainHero.Get_moveOnlyLeft() == true && MainHero.Get_onlyOneAnimation() == true)	//Движение влево
			{
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(true);
				MainHero.Set_onlyOneAnimation(false);

				MainHero.HeroMoveLeft(time);
			}

			if (Keyboard::isKeyPressed(Keyboard::W) && MainHero.Get_moveOnlyLeft() == true && MainHero.Get_moveOnlyRight() == true && MainHero.Get_onlyOneAnimation() == true)			//Движение вверх
			{
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(false);
				MainHero.Set_onlyOneAnimation(false);

				MainHero.HeroMoveTop(time, false, false, false);
			}

			if (Keyboard::isKeyPressed(Keyboard::S) && MainHero.Get_moveOnlyLeft() == true && MainHero.Get_moveOnlyRight() == true && MainHero.Get_onlyOneAnimation() == true)			//Движение вниз
			{
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(true);
				MainHero.Set_onlyOneAnimation(false);

				MainHero.HeroMoveDown(time, false, false, false);
			}

BattleIdleAnimation:

			if (MainHero.Get_buttonIsPressed() == false) {														//AFK
				if (MainHero.Get_previousDirectionMove() == false)MainHero.HeroIdleRight(time);
				else MainHero.HeroIdleLeft(time);
			}
		}
	}


	if (MainHero.Get_battleMode() == false) {																	//Мирный мод

		MainHero.Set_buttonIsPressed(false);
		MainHero.Set_moveOnlyRight(true);
		MainHero.Set_moveOnlyLeft(true);
		MainHero.Set_crouchCheck(true);
		MainHero.Set_crouchAviable(false);
		MainHero.Set_onlyOneAnimation(true);
		MainHero.Set_onlyOneAnimationOneDir(true);

		if (MainHero.Get_slideAviable() == true)																//Скольжение
		{
			MainHero.HeroSlideChoise(time);
		}
		if (MainHero.Get_jumpAviable() == true)																	//Прыжок
		{
			MainHero.HeroJumpChoise(time);
		}
		if (MainHero.Get_jumpLargeAviable() == true)															//Длинный Прыжок
		{
			MainHero.HeroJumpLargeChoise(time);
		}
		if (MainHero.Get_battleModeAvaible() == true) {															//Переключение на боевой мод
			if (MainHero.Get_previousDirectionMove() == false) {
				MainHero.HeroChangeModToBattleRight(time);
			}
			if (MainHero.Get_previousDirectionMove() == true) {
				MainHero.HeroChangeModToBattleLeft(time);
			}
		}

		//Проверка, выполняется ли специальное действие, при котором отключается управление с клавиатуры
		if (MainHero.Get_slideAviable() == true || MainHero.Get_jumpAviable() == true || MainHero.Get_jumpLargeAviable() == true || MainHero.Get_battleModeAvaible()==true) MainHero.Set_controlAviable(false);
		else MainHero.Set_controlAviable(true);
		
		if (MainHero.Get_controlAviable() == true) {															//Если управление с клавиатуры доступно

			if (MainHero.Get_battleMode() == true) goto CivilIdleAnimation;										//Кадр-затычка

			if (Keyboard::isKeyPressed(Keyboard::Z) && MainHero.Get_onlyOneAnimation() == true)					//Команда переключения в боевой мод
			{
				MainHero.Set_onlyOneAnimation(false);
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_battleModeAvaible(true);
			}

			if (MainHero.Get_cooldownAnimationJump() > 0)MainHero.Change_cooldownAnimationJump(-time);			//Если управляем персонажем, откатывается возможность прыгать
			if (MainHero.Get_cooldownAnimationSlide() > 0)MainHero.Change_cooldownAnimationSlide(-time);		//Если управляем персонажем, откатывается возможность скользить

			StaminaRest(MainHero, stime, 30);															//Восстановление выносливости

			if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::S) && MainHero.Get_onlyOneAnimation() == true)	//Движение вправо/вниз
			{
				MainHero.Set_moveRight(true);
				MainHero.Set_moveOnlyRight(false);
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(false);
				MainHero.Set_onlyOneAnimation(false);

				if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_speedXH() >= 0.11 && MainHero.Get_speedXY() >= 0.11 && MainHero.Get_cooldownAnimationSlide() <= 0)//ОШИБКА: НЕ ВЫПОЛНЯЕТСЯ ПРОВЕРКА
				{
					MainHero.Set_moveRight(false);
					MainHero.Set_crouchCheck(false);
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_slideAviable(true);
					MainHero.HeroSlideChoise(time);
				}
				else {
					if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_onlyOneAnimationOneDir() == true)
					{
						MainHero.Set_moveRight(false);
						MainHero.Set_crouchCheck(false);
						MainHero.Set_crouchAviable(true);
						MainHero.Set_onlyOneAnimationOneDir(false);
						MainHero.HeroMoveRightCrouchDown(time);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Space))
				{
					if (MainHero.Get_speedXH() >= 0.1 && MainHero.Get_speedXY() >= 0.1 && MainHero.Get_cooldownAnimationJump() <= 0)
					{
						if (MainHero.Get_speedXH() >= 0.1 && MainHero.Get_speedXH() < 0.15 && MainHero.Get_speedXY() >= 0.1 && MainHero.Get_speedXY() < 0.15) {
							MainHero.Set_jumpAviable(true);
						}
						if (MainHero.Get_speedXH() > 0.15 && MainHero.Get_speedXY() > 0.15) MainHero.Set_jumpLargeAviable(true);
					}
					else MainHero.Set_moveRight(true);
				}

				if (Keyboard::isKeyPressed(Keyboard::LShift) && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.Set_moveRight(false);
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.HeroMoveRightFastDown(time);
				}
				if (Keyboard::isKeyPressed(Keyboard::LAlt) && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.Set_moveRight(false);
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.HeroMoveRightSlowDown(time);
				}
				if (MainHero.Get_moveRight() == true && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.HeroMoveRightDown(time);
				}
			}


			if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::W) && MainHero.Get_onlyOneAnimation() == true)	//Движение вправо/вверх
			{
				MainHero.Set_moveRight(true);
				MainHero.Set_moveOnlyRight(false);
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(false);
				MainHero.Set_onlyOneAnimation(false);

				if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_speedXH() >= 0.11  && MainHero.Get_speedXY() <= -0.11 && MainHero.Get_cooldownAnimationSlide() <= 0)
				{
					MainHero.Set_moveRight(false);
					MainHero.Set_crouchCheck(false);
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_slideAviable(true);
					MainHero.HeroSlideChoise(time);
				}
				else {
					if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_onlyOneAnimationOneDir() == true)
					{
						MainHero.Set_moveRight(false);
						MainHero.Set_crouchCheck(false);
						MainHero.Set_crouchAviable(true);
						MainHero.Set_onlyOneAnimationOneDir(false);
						MainHero.HeroMoveRightCrouchUp(time);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Space))
				{
					if (MainHero.Get_speedXH() >= 0.1 && MainHero.Get_speedXY() <= -0.1 && MainHero.Get_cooldownAnimationJump() <= 0)
					{
						if (MainHero.Get_speedXH() >= 0.1 && MainHero.Get_speedXH() < 0.15 && MainHero.Get_speedXY() <= -0.1 && MainHero.Get_speedXY() > -0.15) {
							MainHero.Set_jumpAviable(true);
						}
						if (MainHero.Get_speedXH() > 0.15 && MainHero.Get_speedXY() < -0.15) MainHero.Set_jumpLargeAviable(true);
					}
					else MainHero.Set_moveRight(true);
				}

				if (Keyboard::isKeyPressed(Keyboard::LShift) && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_moveRight(false);
					MainHero.HeroMoveRightFastUp(time);
				}
				if (Keyboard::isKeyPressed(Keyboard::LAlt) && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_moveRight(false);
					MainHero.HeroMoveRightSlowUp(time);
				}
				if (MainHero.Get_moveRight() == true && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.HeroMoveRightUp(time);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::D) && MainHero.Get_moveOnlyRight() == true && MainHero.Get_onlyOneAnimation() == true)	//Движение вправо
			{
				MainHero.Set_moveRight(true);
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(false);
				MainHero.Set_onlyOneAnimation(false);

				if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_speedXH() > 0.11 && MainHero.Get_cooldownAnimationSlide() <= 0)
				{
					MainHero.Set_moveRight(false);
					MainHero.Set_crouchCheck(false);
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_slideAviable(true);
					MainHero.HeroSlideChoise(time);
				}
				else {
					if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_onlyOneAnimationOneDir() == true)
					{
						MainHero.Set_moveRight(false);
						MainHero.Set_crouchCheck(false);
						MainHero.Set_crouchAviable(true);
						MainHero.Set_onlyOneAnimationOneDir(false);
						MainHero.HeroMoveRightCrouch(time);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Space))
				{
					if (MainHero.Get_speedXH() >= 0.1 && MainHero.Get_cooldownAnimationJump() <= 0)
					{
						if (MainHero.Get_speedXH() >= 0.1 && MainHero.Get_speedXH() < 0.15) {
							MainHero.Set_jumpAviable(true);
						}
						if (MainHero.Get_speedXH() >= 0.15) MainHero.Set_jumpLargeAviable(true);
					}
					else MainHero.Set_moveRight(true);
				}

				if (Keyboard::isKeyPressed(Keyboard::LShift) && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_moveRight(false);
					MainHero.HeroMoveRightFast(time);
				}
				if (Keyboard::isKeyPressed(Keyboard::LAlt) && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_moveRight(false);
					MainHero.HeroMoveRightSlow(time);
				}
				if (MainHero.Get_moveRight() == true && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.HeroMoveRight(time);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::S) && MainHero.Get_onlyOneAnimation() == true)	//Движение влево/вниз
			{
				MainHero.Set_moveLeft(true);
				MainHero.Set_moveOnlyLeft(false);
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(true);
				MainHero.Set_onlyOneAnimation(false);

				if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_speedXH() <= -0.11  && MainHero.Get_speedXY() >= 0.11 && MainHero.Get_cooldownAnimationSlide() <= 0)
				{
					MainHero.Set_moveLeft(false);
					MainHero.Set_crouchCheck(false);
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_slideAviable(true);
					MainHero.HeroSlideChoise(time);
				}
				else {
					if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_onlyOneAnimationOneDir() == true)
					{
						MainHero.Set_moveLeft(false);
						MainHero.Set_crouchCheck(false);
						MainHero.Set_crouchAviable(true);
						MainHero.Set_onlyOneAnimationOneDir(false);
						MainHero.HeroMoveLeftCrouchDown(time);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Space))
				{
					if (MainHero.Get_speedXH() <= -0.1 && MainHero.Get_speedXY() >= 0.1 && MainHero.Get_cooldownAnimationJump() <= 0)
					{
						if (MainHero.Get_speedXH() <= -0.1 && MainHero.Get_speedXH() > -0.15 && MainHero.Get_speedXY() >= 0.1 && MainHero.Get_speedXY() < 0.15) {
							MainHero.Set_jumpAviable(true);
						}
						if (MainHero.Get_speedXH() < -0.15 && MainHero.Get_speedXY() > 0.15) MainHero.Set_jumpLargeAviable(true);
					}
					else MainHero.Set_moveLeft(true);
				}

				if (Keyboard::isKeyPressed(Keyboard::LShift) && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_moveLeft(false);
					MainHero.HeroMoveLeftFastDown(time);
				}
				if (Keyboard::isKeyPressed(Keyboard::LAlt) && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_moveLeft(false);
					MainHero.HeroMoveLeftSlowDown(time);
				}
				if (MainHero.Get_moveLeft() == true && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.HeroMoveLeftDown(time);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::W) && MainHero.Get_onlyOneAnimation() == true)	//Движение влево/вверх
			{
				MainHero.Set_moveLeft(true);
				MainHero.Set_moveOnlyLeft(false);
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(true);
				MainHero.Set_onlyOneAnimation(false);

				if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_speedXH() <= -0.11  && MainHero.Get_speedXY() <= -0.11 && MainHero.Get_cooldownAnimationSlide() <= 0)
				{
					MainHero.Set_moveLeft(false);
					MainHero.Set_crouchCheck(false);
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_slideAviable(true);
					MainHero.HeroSlideChoise(time);
				}
				else {
					if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_onlyOneAnimationOneDir() == true)
					{
						MainHero.Set_moveLeft(false);
						MainHero.Set_crouchCheck(false);
						MainHero.Set_crouchAviable(true);
						MainHero.Set_onlyOneAnimationOneDir(false);
						MainHero.HeroMoveLeftCrouchUp(time);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Space))
				{
					if (MainHero.Get_speedXH() <= -0.1 && MainHero.Get_speedXY() <= -0.1 && MainHero.Get_cooldownAnimationJump() <= 0)
					{
						if (MainHero.Get_speedXH() <= -0.1 && MainHero.Get_speedXH() > -0.15 && MainHero.Get_speedXY() <= -0.1 && MainHero.Get_speedXY() > -0.15) {
							MainHero.Set_jumpAviable(true);
						}
						if (MainHero.Get_speedXH() < -0.15 && MainHero.Get_speedXY() < -0.15) MainHero.Set_jumpLargeAviable(true);
					}
					else MainHero.Set_moveLeft(true);
				}

				if (Keyboard::isKeyPressed(Keyboard::LShift) && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_moveLeft(false);
					MainHero.HeroMoveLeftFastUp(time);
				}
				if (Keyboard::isKeyPressed(Keyboard::LAlt) && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_moveLeft(false);
					MainHero.HeroMoveLeftSlowUp(time);
				}
				if (MainHero.Get_moveLeft() == true && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.HeroMoveLeftUp(time);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::A) && MainHero.Get_moveOnlyLeft() == true && MainHero.Get_onlyOneAnimation() == true)	//Движение влево
			{
				MainHero.Set_moveLeft(true);
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(true);
				MainHero.Set_onlyOneAnimation(false);

				if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_speedXH() <= -0.11 && MainHero.Get_cooldownAnimationSlide() <= 0)
				{
					MainHero.Set_moveLeft(false);
					MainHero.Set_crouchCheck(false);
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_slideAviable(true);
					MainHero.HeroSlideChoise(time);
				}
				else {
					if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_onlyOneAnimationOneDir() == true)
					{
						MainHero.Set_moveLeft(false);
						MainHero.Set_crouchCheck(false);
						MainHero.Set_crouchAviable(true);
						MainHero.Set_onlyOneAnimationOneDir(false);
						MainHero.HeroMoveLeftCrouch(time);
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Space))
				{
					if (MainHero.Get_speedXH() <= -0.1 && MainHero.Get_cooldownAnimationJump() <= 0)
					{
						if (MainHero.Get_speedXH() <= -0.1 && MainHero.Get_speedXH() > -0.15) {
							MainHero.Set_jumpAviable(true);
						}
						if (MainHero.Get_speedXH() < -0.15) MainHero.Set_jumpLargeAviable(true);
					}
					else MainHero.Set_moveLeft(true);
				}

				if (Keyboard::isKeyPressed(Keyboard::LShift) && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_moveLeft(false);
					MainHero.HeroMoveLeftFast(time);
				}
				if (Keyboard::isKeyPressed(Keyboard::LAlt) && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.Set_onlyOneAnimationOneDir(false);
					MainHero.Set_moveLeft(false);
					MainHero.HeroMoveLeftSlow(time);
				}
				if (MainHero.Get_moveLeft() == true && MainHero.Get_onlyOneAnimationOneDir() == true)
				{
					MainHero.HeroMoveLeft(time);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::W) && MainHero.Get_moveOnlyLeft() == true && MainHero.Get_moveOnlyRight() == true && MainHero.Get_onlyOneAnimation() == true)			//Движение вверх
			{
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(false);
				MainHero.Set_onlyOneAnimation(false);

				if (Keyboard::isKeyPressed(Keyboard::LShift) && MainHero.Get_onlyOneAnimationOneDir() == true) { MainHero.Set_onlyOneAnimationOneDir(false); MainHero.HeroMoveTop(time, true, false, false); MainHero.Set_crouchCheck(false); }
				else
					if (Keyboard::isKeyPressed(Keyboard::LAlt) && MainHero.Get_onlyOneAnimationOneDir() == true) { MainHero.Set_onlyOneAnimationOneDir(false); MainHero.HeroMoveTop(time, false, true, false); MainHero.Set_crouchCheck(false); }
					else
						if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_onlyOneAnimationOneDir() == true) { MainHero.Set_onlyOneAnimationOneDir(false); MainHero.HeroMoveTop(time, false, false, true); MainHero.Set_crouchCheck(false); MainHero.Set_crouchAviable(true);}
						else
							MainHero.HeroMoveTop(time, false, false, false);
			}

			if (Keyboard::isKeyPressed(Keyboard::S) && MainHero.Get_moveOnlyLeft() == true && MainHero.Get_moveOnlyRight() == true && MainHero.Get_onlyOneAnimation() == true)			//Движение вниз
			{
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_previousDirectionMove(true);
				MainHero.Set_onlyOneAnimation(false);

				if (Keyboard::isKeyPressed(Keyboard::LShift) && MainHero.Get_onlyOneAnimationOneDir() == true) { MainHero.Set_onlyOneAnimationOneDir(false); MainHero.HeroMoveDown(time, true, false, false); MainHero.Set_crouchCheck(false); }
				else
					if (Keyboard::isKeyPressed(Keyboard::LAlt) && MainHero.Get_onlyOneAnimationOneDir() == true) { MainHero.Set_onlyOneAnimationOneDir(false); MainHero.HeroMoveDown(time, false, true, false); MainHero.Set_crouchCheck(false); }
					else
						if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_onlyOneAnimationOneDir() == true) { MainHero.Set_onlyOneAnimationOneDir(false); MainHero.HeroMoveDown(time, false, false, true); MainHero.Set_crouchCheck(false); MainHero.Set_crouchAviable(true);}
						else
							MainHero.HeroMoveDown(time, false, false, false);
			}

			if (Keyboard::isKeyPressed(Keyboard::C) && MainHero.Get_crouchCheck() == true && MainHero.Get_onlyOneAnimation() == true && MainHero.Get_onlyOneAnimationOneDir() == true)//Присесть		
			{
				MainHero.Set_onlyOneAnimationOneDir(false);
				MainHero.Set_onlyOneAnimation(false);
				MainHero.Set_buttonIsPressed(true);
				MainHero.Set_crouchAviable(true);
				if (MainHero.Get_previousDirectionMove() == false) MainHero.HeroIdleCrouchRight(time);									//Присесть при малой скорости
				else MainHero.HeroIdleCrouchLeft(time);
			}

		CivilIdleAnimation:																												//Метка-затычка кадра

			if (MainHero.Get_buttonIsPressed() == false) {																				//AFK
				if (MainHero.Get_previousDirectionMove() == false)MainHero.HeroIdleRight(time);
				else MainHero.HeroIdleLeft(time);
			}
		}
	}
}

