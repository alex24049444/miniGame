//Определение всех функций класса "ClassNPCFriendlyDBunny"
#include "ClassNPCFriendlyDBunny.h"
#include "OptimizedFunctionsAnimation.h"
#include "EnginePhysics.h"
#include "OptimizedRandom.h"

void NPCFriendlyBunny::Logic(float time)			//Функция логики кролика
{

	if (currentActionTime > 0) {								//Пока есть время на выполнение анимации
		currentActionTime -= time;								//Время на поспроизведение анимации уменьшается
	}
	else														//Если время вышло
	{
		currentAction = RandomBetweenInt(1, 8);					//Определяется, какое действие будет выполняться
		currentActionTime = RandomBetweenDouble(4, 6);			//Определяется время, в течении которого действие будет выполняться.
		currentActionTime = currentActionTime / logicReaction;	//А деление на logicReaction необходимо, чтобы потом не пришлось каждый раз currentActionTime -= time * logicReaction;
	}

	switch (currentAction)							//Количество case по количеству анимаций
	{
	case 1:											
		BunnyEatDown(time);							//Анимация выполняется
		break;
	case 2:
		BunnyEatLeft(time);
		break;
	case 3:
		BunnyEatRight(time);
		break;
	case 4:
		BunnyEatTop(time);
		break;
	case 5:
		BunnyMoveDown(time);
		break;
	case 6:
		BunnyMoveLeft(time);
		break;
	case 7:
		BunnyMoveRight(time);
		break;
	case 8:
		BunnyMoveTop(time);
		break;
	default:										//Дефолт, при выходе за пределы:
		currentActionTime = 0;
		currentAction = 0;
		break;
	}
}

int NPCFriendlyBunny::BunnyMoveRight(float time)	//Кролик двигается вправо
{
	Physics(speedNX, speedNY, time, clutchObj, 0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 70, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyMoveLeft(float time)		//Кролик двигается влево
{
	Physics(speedNX, speedNY, time, clutchObj, -0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 105, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyMoveTop(float time)		//Кролик двигается вверх
{
	Physics(speedNX, speedNY, time, clutchObj, 0, -0.1, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 35, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyMoveDown(float time)		//Кролик двигается вниз
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0.1, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 0, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatRight(float time)		//Кролик ест вправо
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 210, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatLeft(float time)		//Кролик ест влево
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 245, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatTop(float time)		//Кролик ест вверх
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 180, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatDown(float time)		//Кролик ест вниз
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 145, 35, 35);
	return 0;
}