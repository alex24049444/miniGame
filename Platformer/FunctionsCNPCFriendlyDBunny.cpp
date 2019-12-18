//����������� ���� ������� ������ "ClassNPCFriendlyDBunny"
#include "ClassNPCFriendlyDBunny.h"
#include "OptimizedFunctionsAnimation.h"
#include "EnginePhysics.h"
#include "OptimizedRandom.h"

void NPCFriendlyBunny::Logic(float time)			//������� ������ �������
{

	if (currentActionTime > 0) {								//���� ���� ����� �� ���������� ��������
		currentActionTime -= time;								//����� �� ��������������� �������� �����������
	}
	else														//���� ����� �����
	{
		currentAction = RandomBetweenInt(1, 8);					//������������, ����� �������� ����� �����������
		currentActionTime = RandomBetweenDouble(4, 6);			//������������ �����, � ������� �������� �������� ����� �����������.
		currentActionTime = currentActionTime / logicReaction;	//� ������� �� logicReaction ����������, ����� ����� �� �������� ������ ��� currentActionTime -= time * logicReaction;
	}

	switch (currentAction)							//���������� case �� ���������� ��������
	{
	case 1:											
		BunnyEatDown(time);							//�������� �����������
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
	default:										//������, ��� ������ �� �������:
		currentActionTime = 0;
		currentAction = 0;
		break;
	}
}

int NPCFriendlyBunny::BunnyMoveRight(float time)	//������ ��������� ������
{
	Physics(speedNX, speedNY, time, clutchObj, 0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 70, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyMoveLeft(float time)		//������ ��������� �����
{
	Physics(speedNX, speedNY, time, clutchObj, -0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 105, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyMoveTop(float time)		//������ ��������� �����
{
	Physics(speedNX, speedNY, time, clutchObj, 0, -0.1, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 35, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyMoveDown(float time)		//������ ��������� ����
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0.1, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 0, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatRight(float time)		//������ ��� ������
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 210, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatLeft(float time)		//������ ��� �����
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 245, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatTop(float time)		//������ ��� �����
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 180, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatDown(float time)		//������ ��� ����
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 4, sprite, 35, 0, 145, 35, 35);
	return 0;
}