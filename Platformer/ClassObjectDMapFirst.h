#pragma once
#include "ClassObject.h"

//Первая карта
class ObjectMapFirst :public Object
{
public:
	ObjectMapFirst() {
	
	crossable = false;
	animated = false;
	
	xR = 0;
	yR = 0;
	xM = 0;
	yM = 0;
	wM = 4000;
	hM = 2250;
	xRReal = 0;
	yRReal = 0;
	wRReal = 4000;
	hRReal = 2250;
	clutch = 1;

	tracking = false;
	trackingCoefficient = 0;

	passable = true;
	passableJump = false;
	passableSlide = false;
	passableCrouch = false;

	imageObject.loadFromFile("Environment/Maps/TestMap5.png");
	imageObject.createMaskFromColor(Color(255, 255, 255));					//Прозрачность белого
	textureObject.loadFromImage(imageObject);
	spriteObject.setTexture(textureObject);
	spriteObject.setTextureRect(IntRect(xM, yM, wM, hM));
	spriteObject.setPosition(xR, yR);
	layer = 1;
	}
};

