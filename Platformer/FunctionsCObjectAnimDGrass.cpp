#include "ClassObjectAnimDGrass.h"
#include "OptimizedFunctionsAnimation.h"

int ObjectAnimGrass::Animation(float time)												//��������
{
	CycleAnimation(currentFrame, time, animSpeed, 4, spriteObject, wM, 0, yM, wM, hM);
	return 0;
}
