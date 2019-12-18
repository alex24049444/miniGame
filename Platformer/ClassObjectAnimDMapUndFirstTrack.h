#pragma once
#include "ClassObjectAnim.h"

class ObjectTrackMapUndFirst :public ObjectAnim
{
public:
	ObjectTrackMapUndFirst()
	{
		crossable = false;
		animated = false;
		layer = 0;

		xR = -10000;
		yR = -5000;
		xM = 0;
		yM = 0;
		wM = 3250;
		hM = 1000;
		xRReal = 0;
		yRReal = 0;
		wRReal = 0;
		hRReal = 0;
		clutch = 1;

		tracking = true;
		trackingCoefficient = 1.1;

		passable = true;
		passableJump = false;
		passableSlide = false;
		passableCrouch = false;

		imageObject.loadFromFile("Environment/Maps/undMap3.png");
		imageObject.createMaskFromColor(Color(255, 255, 255));					//Прозрачность белого
		textureObject.loadFromImage(imageObject);
		spriteObject.setTexture(textureObject);
		spriteObject.setTextureRect(IntRect(xM, yM, wM, hM));
		spriteObject.setPosition(xR, yR);
	}
};

