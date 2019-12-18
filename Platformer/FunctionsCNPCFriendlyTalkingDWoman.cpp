//Определение всех функций класса "NPCFriendlyTalkingWoman"
#include "ClassNPCFriendlyTalkingDWoman.h"
#include "OptimizedFunctionsAnimation.h"
#include "OptimizedRandom.h"

void NPCFriendlyTalkingWoman::Logic(float time)
{
	if (currentActionTime > 0) {								//Пока есть время на выполнение анимации
		currentActionTime -= time;								//Время на поспроизведение анимации уменьшается
	}
	else														//Если время вышло
	{
		currentAction = RandomBetweenInt(1, 2);					//Определяется, какое действие будет выполняться
		currentActionTime = RandomBetweenDouble(5, 10);			//Определяется время, в течении которого действие будет выполняться.
		currentActionTime = currentActionTime / logicReaction;	//А деление на logicReaction необходимо, чтобы потом не пришлось каждый раз currentActionTime -= time * logicReaction;
	}

	switch (currentAction)										//Анимация выполняется в соответствии со своим номером
	{
	case 1:
		WomanIdleRight(time);					
		break;
	case 2:		
		WomanIdleLeft(time);					
		break;
	default:
		currentActionTime = 0;									//Номер текущего действия сбрасывается в 0 (default)
		currentAction = 0;										//Время на текущее действие сбрасывается в 0 (default)
		break;
	}
}

void NPCFriendlyTalkingWoman::Draw(float time)							//Переопределение, т.к. не двигается и не нужно изменять местоположение итд.
{
	return;																//Заглушка для movableN=false;
}

int NPCFriendlyTalkingWoman::WomanIdleRight(float time)					//Бездействие вправо
{
	dirN = 0;
	CycleAnimation(currentFrame, time, 0.01, 16, sprite, 50, 0, 0, 50, 63);
	return 0;
}

int NPCFriendlyTalkingWoman::WomanIdleLeft(float time)					//Бездействие влево
{
	dirN = 0;
	CycleAnimation(currentFrame, time, 0.01, 16, sprite, 50, 50, 0, -50, 63);
	return 0;
}