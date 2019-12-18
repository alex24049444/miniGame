#include "ClassNPCEnemyCommonDHight.h"
#include "OptimizedFunctionsAnimation.h"
#include "EnginePhysics.h"
#include "OptimizedRandom.h"

void NPCEnemyCommonDHight::Logic(float time) {

	if (currentActionTime > 0) {								//���� ���� ����� �� ���������� ��������
		currentActionTime -= time;								//����� �� ��������������� �������� �����������
	}
	else														//���� ����� �����
	{
		currentAction = RandomBetweenInt(1, 4);					//������������, ����� �������� ����� �����������
		currentActionTime = RandomBetweenDouble(4, 6);			//������������ �����, � ������� �������� �������� ����� �����������.
		currentActionTime = currentActionTime / logicReaction;	//� ������� �� logicReaction ����������, ����� ����� �� �������� ������ ��� currentActionTime -= time * logicReaction;
	}
	if (ch1 == 0) {
		if (lifeDL)
		{
			Respawn(time);
		};
		ch1++;
	}
	switch (currentAction)							//���������� case �� ���������� ��������
	{
	case 1:
		MoveLeft(time);
		break;
	case 2:
		MoveRight(time);
		break;
	case 3:
		IdleRight(time);
		break;
	case 4:
		IdleLeft(time);
		break;
	default:										//������, ��� ������ �� �������:
		currentActionTime = 0;
		currentAction = 0;
		break;
	};
};// ���� ��� ���

int NPCEnemyCommonDHight::Respawn(float time) // �������
{
	UncycleAnimationMob(currentUncycleFrame, time, right, 0.0004, sprite, 96, 384, 96, 96, 1);

	return 0;
};
int NPCEnemyCommonDHight::MoveLeft(float time) // ��� �����
{
	Physics(speedNX, speedNY, time, clutchObj, -0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 8, sprite, 96, 0, 110, 96, 110);

	return 0;
};
int NPCEnemyCommonDHight::MoveRight(float time) //��� ������
{
	Physics(speedNX, speedNY, time, clutchObj, 0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 8, sprite, 96, 100, 110, -96, 110);

	return 0;
};
int NPCEnemyCommonDHight::IdleRight(float time)//�������� ������ ������
{
	dirN = 0;
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 4, sprite, 96, 100, 0, -96, 110);
	return 0;
};
int NPCEnemyCommonDHight::IdleLeft(float time) //�������� ������ �����
{
	dirN = 0;
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 4, sprite, 96, 0, 0, 96, 110);

	return 0;
};
/*
int NPCEnemyCommonDHight::MobsDieRight(float time){}; ����� ���� ���
*/