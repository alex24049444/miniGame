#include "ClassNPCEnemyCommonDLight.h"
#include "ClassHero.h"
#include "OptimizedFunctionsAnimation.h"
#include "EnginePhysics.h"
#include "OptimizedRandom.h"

void NPCEnemyCommonDLight::Logic(float time) {

	if (currentActionTime > 0) {								//���� ���� ����� �� ���������� ��������
		currentActionTime -= time;								//����� �� ��������������� �������� �����������
	}
	else														//���� ����� �����
	{
		currentAction = RandomBetweenInt(1, 4);					//������������, ����� �������� ����� �����������
		currentActionTime = RandomBetweenDouble(20, 30);			//������������ �����, � ������� �������� �������� ����� �����������.
		currentActionTime = currentActionTime / logicReaction;	//� ������� �� logicReaction ����������, ����� ����� �� �������� ������ ��� currentActionTime -= time * logicReaction;
	}
	
	if (ch1 == 0) {
		if (lifeDL)
		{
			Respawn(time);
		};
		ch1++;
	}
	if (patrolmod) {
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
	}
	else if (!patrolmod) {
		switch (currentAction)							//���������� case �� ���������� ��������
		{
		case 1:
			IdleRight(time);
			break;
		case 2:
			IdleLeft(time);
			break;
		
		default:										//������, ��� ������ �� �������:
			currentActionTime = 0;
			currentAction = 0;
			break;
		};

	}
};// ���� ��� ���


int NPCEnemyCommonDLight::Respawn(float time) // �������
{
	UncycleAnimationMob(currentUncycleFrame, time, right, 0.0004, sprite, 96, 384, 96, 96, 1);

	return 0;
};
int NPCEnemyCommonDLight::MoveLeft(float time) // ��� �����
{
	Physics(speedNX, speedNY, time, clutchObj, -0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 8, sprite, 96, 0, 96, 96, 96);

	return 0;
};
int NPCEnemyCommonDLight::MoveRight(float time) //��� ������
{
	Physics(speedNX, speedNY, time, clutchObj, 0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.005, 8, sprite, 96, 100, 96, -96, 96);

	return 0;
};
int NPCEnemyCommonDLight::IdleRight(float time)//�������� ������ ������
{
	dirN = 0;
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 4, sprite, 96, 100, 0, -96, 96);
	return 0;
};
int NPCEnemyCommonDLight::IdleLeft(float time) //�������� ������ �����
{
	dirN = 0;
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 4, sprite, 96, 0, 0, 96, 96);

	return 0;
};
/*
int NPCEnemyCommonDLight::MobsDieRight(float time){}; ����� ���� ���
*/