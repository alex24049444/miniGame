/*
Описание всех функций Героя.
*/


#include "ClassHero.h";
#include "OptimizedFunctionsAnimationCHero.h"
#include "OptimizedFunctionsAnimation.h"
#include "EnginePhysics.h"

/*
Функции передвижения героя.
Получаем х и у, локально увеличиваем нужное значение по х/у,
Передаем в функцию карты и проверяем, не ушли ли мы за карту.
Если все ОК, изменяем фактическое положение и спрайт
*/


void Hero::Draw(float time)												//Физика на отрисовку персонажа, связывает анимацию и физику
{
																		/*
																		dirH: РОЗА НАПРАВЛЕНИЙ
																		7 4 8
																		 ↖↑↗
																		3←0→1
																		 ↙↓↘
																		6 2 5
																		*/
	dxH = speedHX; dyH = speedHY;										//Передаем значения ускорения
	xHReal += dxH * time;												//Физика
	yHReal += dyH * time;												//Положенение реальной модели в пространстве
	xH = xHReal - xHRealInside;											//Положение виртуальной модели в пространстве
	yH = yHReal - yHRealInside;
	sprite.setPosition(xH, yH);											//Установть точку отрисовки на позиции хН,уН
	layerH = trunc(yHReal + hHRealInside);								//Отбросили дробную часть, если нужно округлить: layerH = round(yHReal + hHRealInside);	
}


void Hero::HeroSlideChoise(float time)									//Выбор направления скольжения
{

	switch (dirH)														//Тот самый dirН по розе направлений
	{
	case 1: HeroSlideRight(time); break;
	case 3: HeroSlideLeft(time); break;
	case 5:	HeroSlideRightDown(time); break;
	case 6: HeroSlideLeftDown(time); break;
	case 7: HeroSlideLeftUp(time); break;
	case 8: HeroSlideRightUp(time); break;
	}
}

void Hero::HeroJumpChoise(float time)									//Выбор направления прыжка
{

	switch (dirH)
	{
	case 1: HeroJumpRight(time); break;
	case 3: HeroJumpLeft(time); break;
	case 5:	HeroJumpRightDown(time); break;
	case 6: HeroJumpLeftDown(time); break;
	case 7: HeroJumpLeftUp(time); break;
	case 8: HeroJumpRightUp(time); break;
	}
}

void Hero::HeroJumpLargeChoise(float time)								//Выбор направления мощного прыжка
{

	switch (dirH)
	{
	case 1: HeroJumpLargeRight(time); break;
	case 3: HeroJumpLargeLeft(time); break;
	case 5:	HeroJumpLargeRightDown(time); break;
	case 6: HeroJumpLargeLeftDown(time); break;
	case 7: HeroJumpLargeLeftUp(time); break;
	case 8: HeroJumpLargeRightUp(time); break;
	}
}

int Hero::HeroIdleRight(float time)										//Безделие взгляд вправо
{
	SetRealSize(40, 59, 22, 15);
	dirH = 0;
	Physics(speedHX, speedHY, time, clutchObj, 0, 0, 1, 1, 0, 0);
	if(battleMode==false) CycleAnimation(currentFrame, time, 0.004, 4, sprite, 100, 0, 74, 100, 74);
	else CycleAnimation(currentFrame, time, 0.004, 4, sprite, 100, 0, 1258, 100, 74);
	return 0;
}

int Hero::HeroIdleCrouchRight(float time)								//Безделие сидя взгляд вправо
{
	SetRealSize(40, 59, 22, 15);
	dirH = 0;
	Physics(speedHX, speedHY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 4, sprite, 100, 0, 148, 100, 74);
	return 0;
}

int Hero::HeroIdleLeft(float time)										//Безделие взгляд влево
{
	SetRealSize(40, 59, 22, 15);
	dirH = 0;
	Physics(speedHX, speedHY, time, clutchObj, 0, 0, 1, 1, 0, 0);
	if (battleMode == false) CycleAnimation(currentFrame, time, 0.004, 4, sprite, 100, 100, 74, -100, 74);
	else CycleAnimation(currentFrame, time, 0.004, 4, sprite, 100, 100, 1258, -100, 74);
	return 0;
}

int Hero::HeroIdleCrouchLeft(float time)								//Безделие сидя взгляд влево
{
	SetRealSize(40, 59, 22, 15);
	dirH = 0;
	Physics(speedHX, speedHY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 4, sprite, 100, 100, 148, -100, 74);
	return 0;
}
/*
Функции движения вверх/вниз
3 булевские переменные отвечают за скорость движения
*/

int Hero::HeroMoveTop(float time, bool fast,bool slow, bool crouch)		//Бег вверх
{
	SetRealSize(38, 54, 18, 18);
	dirH = 4; 
	if (fast == true) {
		Physics(speedHX, speedHY, time, clutchObj, 0, -0.2, 1, 1, 0, 0);
	}
	else if (slow == true) {
		Physics(speedHX, speedHY, time, clutchObj, 0, -0.04, 1, 1, 0, 0);
	}
	else if (crouch == true) {
		Physics(speedHX, speedHY, time, clutchObj, 0, -0.07, 1, 1, 0, 0);
	}
	else {
		Physics(speedHX, speedHY, time, clutchObj, 0, -0.1, 1, 1, 0, 0);
	}
	if (battleMode == false) CycleAnimation(currentFrame, time, 0.005, 6, sprite, 100, 0, 1110, 100, 74);
	else CycleAnimation(currentFrame, time, 0.005, 6, sprite, 100, 0, 2294, 100, 74);
	return 0;
}

int Hero::HeroMoveDown(float time, bool fast, bool slow, bool crouch)	//Бег вниз
{
	SetRealSize(38, 54, 18, 18);
	dirH = 2;
	if (fast == true) {
		Physics(speedHX, speedHY, time, clutchObj, 0, 0.2, 1, 1, 0, 0);
	}
	else if (slow == true) {
		Physics(speedHX, speedHY, time, clutchObj, 0, 0.04, 1, 1, 0, 0);
	}
	else if (crouch == true) {
		Physics(speedHX, speedHY, time, clutchObj, 0, 0.07, 1, 1, 0, 0);
	}
	else {
		Physics(speedHX, speedHY, time, clutchObj, 0, 0.1, 1, 1, 0, 0);
	}
	if (battleMode == false) CycleAnimation(currentFrame, time, 0.005, 6, sprite, 100, 0, 1184, 100, 74);
	else CycleAnimation(currentFrame, time, 0.005, 6, sprite, 100, 0, 2368, 100, 74);
	return 0;
}


int Hero::HeroMoveRight(float time)										//Бег вправо
{
	SetRealSize(40, 55, 28, 19);
	dirH = 1;
	Physics(speedHX, speedHY, time, clutchObj, 0.1, 0, 1, 1, 0, 0);
	if (battleMode == false) CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 0, 100, 74);
	else CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 2220, 100, 74);
	return 0;
}


int Hero::HeroMoveRightFast(float time)									//Бег вправо быстрый
{
	dirH = 1;
	Physics(speedHX, speedHY, time, clutchObj, 0.2, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 370, 100, 74);
	return 0;
}

int Hero::HeroMoveRightSlow(float time)									//Ходьба вправо
{
	dirH = 1;
	Physics(speedHX, speedHY, time, clutchObj, 0.04, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 222, 100, 74);
	return 0;
}

int Hero::HeroMoveRightCrouch(float time)								//Присед вправо
{
	dirH = 1;
	Physics(speedHX, speedHY, time, clutchObj, 0.07, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 6, sprite, 100, 0, 296, 100, 74);
	return 0;
}
int Hero::HeroMoveRightUp(float time)									//Бег вправо/вверх
{
	SetRealSize(40, 55, 28, 19);
	dirH = 8;
	Physics(speedHX, speedHY, time, clutchObj, 0.1, -0.1, 1, 1, 0, 0);
	if (battleMode == false) CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 0, 100, 74);
	else CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 2220, 100, 74);
	return 0;
}

int Hero::HeroMoveRightFastUp(float time)								//Бег вправо/вверх быстрый
{
	dirH = 8;
	Physics(speedHX, speedHY, time, clutchObj, 0.2, -0.2, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 370, 100, 74);
	return 0;
}

int Hero::HeroMoveRightSlowUp(float time)								//Ходьба вправо/вверх
{
	dirH = 8;
	Physics(speedHX, speedHY, time, clutchObj, 0.04, -0.04, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 222, 100, 74);
	return 0;
}

int Hero::HeroMoveRightCrouchUp(float time)								//Присед вправо/вверх
{
	dirH = 8;
	Physics(speedHX, speedHY, time, clutchObj, 0.07, -0.07, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 6, sprite, 100, 0, 296, 100, 74);
	return 0;
}
int Hero::HeroMoveRightDown(float time)									//Бег вправо/вниз
{
	SetRealSize(40, 55, 28, 19);
	dirH = 5;
	Physics(speedHX, speedHY, time, clutchObj, 0.1, 0.1, 1, 1, 0, 0);
	if (battleMode == false) CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 0, 100, 74);
	else CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 2220, 100, 74);
	return 0;
}

int Hero::HeroMoveRightFastDown(float time)								//Бег вправо/вниз быстрый
{
	dirH = 5;
	Physics(speedHX, speedHY, time, clutchObj, 0.2, 0.2, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 370, 100, 74);
	return 0;
}

int Hero::HeroMoveRightSlowDown(float time)								//Ходьба вправо/вниз
{
	dirH = 5;
	Physics(speedHX, speedHY, time, clutchObj, 0.04, 0.04, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 222, 100, 74);
	return 0;
}

int Hero::HeroMoveRightCrouchDown(float time)							//Присед вправо/вниз
{
	dirH = 5;
	Physics(speedHX, speedHY, time, clutchObj, 0.07, 0.07, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 6, sprite, 100, 0, 296, 100, 74);
	return 0;
}

int Hero::HeroMoveLeft(float time)										//Бег влево
{
	SetRealSize(32, 55, 28, 19);
	dirH = 3;
	Physics(speedHX, speedHY, time, clutchObj, -0.1, 0, 1, 1, 0, 0);
	if (battleMode == false) CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 0, -100, 74);
	else CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 2220, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftFast(float time)									//Бег влево быстрый
{
	dirH = 3;
	Physics(speedHX, speedHY, time, clutchObj, -0.2, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 370, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftSlow(float time)									//Ходьба влево
{	
	dirH = 3;
	Physics(speedHX, speedHY, time, clutchObj, -0.04, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 222, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftCrouch(float time)								// Присед влево
{
	dirH = 3;
	Physics(speedHX, speedHY, time, clutchObj, -0.07, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 6, sprite, 100, 100, 296, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftUp(float time)									//Бег влево/вверх
{
	SetRealSize(32, 55, 28, 19);
	dirH = 7;
	Physics(speedHX, speedHY, time, clutchObj, -0.1, -0.1, 1, 1, 0, 0);
	if (battleMode == false) CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 0, -100, 74);
	else CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 2220, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftFastUp(float time)								//Бег влево/вверх быстрый
{
	dirH = 7;
	Physics(speedHX, speedHY, time, clutchObj, -0.2, -0.2, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 370, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftSlowUp(float time)								//Ходьба влево/вверх
{
	dirH = 7;
	Physics(speedHX, speedHY, time, clutchObj, -0.04, -0.04, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 222, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftCrouchUp(float time)								//Присед влево/вверх
{
	dirH = 7;
	Physics(speedHX, speedHY, time, clutchObj, -0.07, -0.07, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 6, sprite, 100, 100, 296, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftDown(float time)									//Бег влево/вниз
{
	SetRealSize(32, 55, 28, 19);
	dirH = 6;
	Physics(speedHX, speedHY, time, clutchObj, -0.1, 0.1, 1, 1, 0, 0);
	if (battleMode == false) CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 0, -100, 74);
	else CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 2220, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftFastDown(float time)								//Бег влево/вниз быстрый
{
	dirH = 6;
	Physics(speedHX, speedHY, time, clutchObj, -0.2, 0.2, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 370, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftSlowDown(float time)								//Ходьба влево/вниз
{
	dirH = 6;
	Physics(speedHX, speedHY, time, clutchObj, -0.04, 0.04, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 222, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftCrouchDown(float time)							//Присед влево/вниз
{
	dirH = 6;
	Physics(speedHX, speedHY, time, clutchObj, -0.07, 0.07, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 6, sprite, 100, 100, 296, -100, 74);
	return 0;
}

int Hero::HeroSlideRight(float time)									//Скольжение вправо
{
	OnlySlideAnimation(currentUncycleFrame, time, cooldownAnimationSlide, 0.5, slideAviable, dirH, 1, speedHX, speedHY, sprite, 0, 100, 0.1, 0, 0.08, 2, clutchObj, 0.0003, 0, 0.11, 0.4, -0.3, 0.3);
	return 0;
}

int Hero::HeroSlideRightUp(float time)									//Скольжение вправо вверх
{
	OnlySlideAnimation(currentUncycleFrame, time, cooldownAnimationSlide, 0.5, slideAviable, dirH, 8, speedHX, speedHY, sprite, 0, 100, 0.08, -0.08, 0.11, 0.11, clutchObj, 0.0003, -0.0003, 0.11, 0.4, -0.4, -0.11);
	return 0;
}

int Hero::HeroSlideRightDown(float time)								//Скольжение вправо вниз
{
	OnlySlideAnimation(currentUncycleFrame, time, cooldownAnimationSlide, 0.5, slideAviable, dirH, 5, speedHX, speedHY, sprite, 0, 100, 0.08, 0.08, 0.11, 0.11, clutchObj, 0.0003, 0.0003, 0.11, 0.4, 0.11, 0.4);
	return 0;
}

int Hero::HeroSlideLeft(float time)										//Скольжение влево
{
	OnlySlideAnimation(currentUncycleFrame, time, cooldownAnimationSlide, 0.5, slideAviable, dirH, 3, speedHX, speedHY, sprite, 100, -100, -0.1, 0, 0.11, 2, clutchObj, -0.0003, 0, -0.4, -0.11, -0.4, 0.4);
	return 0;
}

int Hero::HeroSlideLeftUp(float time)									//Скольжение влево вверх
{
	OnlySlideAnimation(currentUncycleFrame, time, cooldownAnimationSlide, 0.5, slideAviable, dirH, 7, speedHX, speedHY, sprite, 100, -100, -0.08, -0.08, 0.11, 0.11, clutchObj, -0.0003, -0.0003, -0.4, -0.11, -0.4, -0.11);
	return 0;
}

int Hero::HeroSlideLeftDown(float time)									//Скольжение влево вниз
{	
	OnlySlideAnimation(currentUncycleFrame, time, cooldownAnimationSlide, 0.5, slideAviable, dirH, 6, speedHX, speedHY, sprite, 100, -100, -0.08, 0.08, 0.11, 0.11, clutchObj, -0.0003, 0.0003, -0.4, -0.11, 0.11, 0.4);
	return 0;
}

int Hero::HeroJumpRight(float time)										//Прыжок вправо
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 1.5, jumpAviable, dirH, 1, 0.007, speedHX, speedHY, sprite, 0, 518, 100, 5, 0.15, 0, 0.1, 1, clutchObj, 0.0005, 0, 0.1, 0.2, -0.2, 0.2);
	return 0;
}

int Hero::HeroJumpRightUp(float time)									//Прыжок вправо вверх
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 1.5, jumpAviable, dirH, 8, 0.007, speedHX, speedHY, sprite, 0, 518, 100, 5, 0.1, -0.1, 0.1, 0.1, clutchObj, 0.0007, -0.0007, 0.1, 0.2, -0.2, -0.1);
	return 0;
}

int Hero::HeroJumpRightDown(float time)									//Прыжок вправо вниз
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 1.5, jumpAviable, dirH, 5, 0.007, speedHX, speedHY, sprite, 0, 518, 100, 5, 0.1, 0.1, 0.1, 0.1, clutchObj, 0.0007, 0.0007, 0.1, 0.2, 0.1, 0.2);
	return 0;
}

int Hero::HeroJumpLeft(float time)										//Прыжок влево
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 1.5, jumpAviable, dirH, 3, 0.007, speedHX, speedHY, sprite, 100, 518, -100, 5, -0.15, 0, 0.1, 1, clutchObj, -0.0005, 0, -0.2, -0.1, -0.2, 0.2);
	return 0;
}

int Hero::HeroJumpLeftUp(float time)									//Прыжок влево вверх
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 1.5, jumpAviable, dirH, 7, 0.007, speedHX, speedHY, sprite, 100, 518, -100, 5, -0.1, -0.1, 0.1, 0.1, clutchObj, -0.0007, -0.0007, -0.2, -0.1, -0.2, -0.1);
	return 0;
}

int Hero::HeroJumpLeftDown(float time)									//Прыжок влево вниз
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 1.5, jumpAviable, dirH, 6, 0.007, speedHX, speedHY, sprite, 100, 518, -100, 5, -0.1, 0.1, 0.1, 0.1, clutchObj, -0.0007, 0.0007, -0.2, -0.1, 0.1, 0.2);
	return 0;
}

int Hero::HeroJumpLargeRight(float time)								//Мощный прыжок вправо
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 1, jumpLargeAviable, dirH, 1, 0.01, speedHX, speedHY, sprite, 0, 444, 100, 10, 0.27, 0, 0.1, 1, clutchObj, 0.0006, 0, 0, 0.3, -0.3, 0.3);
	return 0;
}

int Hero::HeroJumpLargeRightUp(float time)								//Мощный прыжок вправо вверх
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 1, jumpLargeAviable, dirH, 8, 0.01, speedHX, speedHY, sprite, 0, 444, 100, 10, 0.2, -0.2, 0.1, 0.1, clutchObj, 0.0008, -0.0008, 0, 0.3, -0.3, 0);
	return 0;
}

int Hero::HeroJumpLargeRightDown(float time)							//Мощный прыжок вправо вниз
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 1, jumpLargeAviable, dirH, 5, 0.01, speedHX, speedHY, sprite, 0, 444, 100, 10, 0.2, 0.2, 0.1, 0.1, clutchObj, 0.0008, 0.0008, 0, 0.3, 0, 0.3);
	return 0;
}

int Hero::HeroJumpLargeLeft(float time)									//Мощный прыжок влево
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 1, jumpLargeAviable, dirH, 3, 0.01, speedHX, speedHY, sprite, 100, 444, -100, 10, -0.27, 0, 0.1, 1, clutchObj, -0.0006, 0, -0.3, 0, -0.3, 0.3);
	return 0;
}

int Hero::HeroJumpLargeLeftUp(float time)								//Мощный прыжок влево вверх
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 1, jumpLargeAviable, dirH, 7, 0.01, speedHX, speedHY, sprite, 100, 444, -100, 10, -0.2, -0.2, 0.1, 0.1, clutchObj, -0.0008, -0.0008, -0.3, 0, -0.3, 0);
	return 0;
}

int Hero::HeroJumpLargeLeftDown(float time)								//Мощный прыжок влево вниз
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 1, jumpLargeAviable, dirH, 6, 0.01, speedHX, speedHY, sprite, 100, 444, -100, 10, -0.2, 0.2, 0.1, 0.1, clutchObj, -0.0008, 0.0008, -0.3, 0, 0, 0.3);
	return 0;
}

int Hero::HeroChangeModToBattleLeft(float time)							//Взгляд влево достает меч
{
	Physics(speedHX, speedHY, time, clutchObj, 0, 0, 1, 1, 0, 0);
	UncycleAnimation(currentUncycleFrame, time, battleModeAvaible, dirH, 3, 0.01, sprite, 100, 1998, -100, 4);
	if (battleModeAvaible == false) battleMode = true;
	return 0;
}

int Hero::HeroChangeModToCivilLeft(float time)							//Взгляд влево убирает меч
{
	Physics(speedHX, speedHY, time, clutchObj, 0, 0, 1, 1, 0, 0);
	UncycleAnimation(currentUncycleFrame, time, battleModeAvaible, dirH, 3, 0.01, sprite, 100, 2072, -100, 4);
	if (battleModeAvaible == false) battleMode = false;
	return 0;
}

int Hero::HeroChangeModToBattleRight(float time)						//Взгляд вправо достает меч
{
	Physics(speedHX, speedHY, time, clutchObj, 0, 0, 1, 1, 0, 0);
	UncycleAnimation(currentUncycleFrame, time, battleModeAvaible, dirH, 1, 0.01, sprite, 0, 1998, 100, 4);
	if (battleModeAvaible == false) battleMode = true;
	return 0;
}

int Hero::HeroChangeModToCivilRight(float time)							//Взгляд вправо убирает меч
{
	Physics(speedHX, speedHY, time, clutchObj, 0, 0, 1, 1, 0, 0);
	UncycleAnimation(currentUncycleFrame, time, battleModeAvaible, dirH, 1, 0.01, sprite, 0, 2072, 100, 4);
	if (battleModeAvaible == false) battleMode = false;
	return 0;
}

int Hero::LightBlowRight(float time)									//Легкий удар вправо
{
	comboTimer += time;														//Увеличиваем комбо таймер
	Physics(speedHX, speedHY, time, clutchObj, 0, 0, 2, 2, 0, 0);							//Физика
	if (comboHitH == 1 && comboH == 2) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableLight, dirH, 1, 0.01, sprite, 0, 1628, 100, 4);
	}
	if (comboHitH == 2 && comboH == 2) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableLight, dirH, 1, 0.01, sprite, 0, 1702, 100, 3);
	}
	if (comboHitH == 3 && comboH == 2) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableLight, dirH, 1, 0.01, sprite, 0, 1850, 100, 3);
	}
	if (comboHitH == 2 && comboH == 1) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableLight, dirH, 1, 0.01, sprite, 0, 1480, 100, 3);
	}
	return 0;
}

int Hero::LightBlowLeft(float time)										//Легкий удар влево
{
	comboTimer += time;														//Увеличиваем комбо таймер
	Physics(speedHX, speedHY, time, clutchObj, 0, 0, 2, 2, 0, 0);							//Физика
	if (comboHitH == 1 && comboH == 2) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableLight, dirH, 1, 0.01, sprite, 100, 1628, -100, 4);
	}
	if (comboHitH == 2 && comboH == 2) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableLight, dirH, 1, 0.01, sprite, 100, 1702, -100, 3);
	}
	if (comboHitH == 3 && comboH == 2) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableLight, dirH, 1, 0.01, sprite, 100, 1850, -100, 3);
	}
	if (comboHitH == 2 && comboH == 1) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableLight, dirH, 1, 0.01, sprite, 100, 1480, -100, 3);
	}
	return 0;
}

int Hero::HeavyBlowRight(float time)									//Тяжелый удар вправо
{
	comboTimer += time;													//Увеличиваем комбо таймер
	Physics(speedHX, speedHY, time, clutchObj, 0, 0, 2, 2, 0, 0);						//Физика
	if (comboHitH == 3 && comboH == 2) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableHeavy, dirH, 1, 0.01, sprite, 0, 1776, 100, 5);
	}
	if (comboHitH == 1 && comboH == 1) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableHeavy, dirH, 1, 0.007, sprite, 0, 1332, 100, 3);
	}
	if (comboHitH == 3 && comboH == 1) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableHeavy, dirH, 1, 0.007, sprite, 0, 1554, 100, 3);
	}
	return 0;
}

int Hero::HeavyBlowLeft(float time)										//Тяжелый удар влево
{
	comboTimer += time;													//Увеличиваем комбо таймер
	Physics(speedHX, speedHY, time, clutchObj, 0, 0, 2, 2, 0, 0);						//Физика
	if (comboHitH == 3 && comboH == 2) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableHeavy, dirH, 1, 0.01, sprite, 100, 1776, -100, 5);
	}
	if (comboHitH == 1 && comboH == 1) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableHeavy, dirH, 1, 0.007, sprite, 100, 1332, -100, 3);
	}
	if (comboHitH == 3 && comboH == 1) {
		UncycleAnimation(currentUncycleFrame, time, hitAviableHeavy, dirH, 1, 0.007, sprite, 100, 1554, -100, 3);
	}
	return 0;
}

//TODO: В каждую функцию, где персонаж как-то изменяется в размерах необходимо добавить SetRealSize для уменьшения хитбокса
void Hero::SetRealSize(float xRealIns, float yRealIns, float wReal, float hReal) {			//Установить новые размеры физической модели персонажа
	if(xHRealInside != xRealIns) xHRealInside = xRealIns;
	if(yHRealInside != yRealIns) yHRealInside = yRealIns;
	if(wHRealInside != wReal) wHRealInside = wReal;
	if(hHRealInside != hReal) hHRealInside = hReal;
}
/*
Функция получения урона персонажем.
*/
void Hero::HeroGetDamage()
{
}