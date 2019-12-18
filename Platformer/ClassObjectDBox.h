#pragma once

#include "ClassObject.h"

//Класс коробки
class ObjectBox : public Object {
public:
	ObjectBox(float _xOnMap, float _yOnMap) {
		crossable = true;
		movableO = true;

		xR = _xOnMap;
		yR = _yOnMap;
		xM = 0;
		yM = 0;
		wM = 23;
		hM = 31;
		xRRealInside = 0;
		yRRealInside = 11;
		xRReal = xR + xRRealInside;
		yRReal = yR + yRRealInside;
		wRReal = 23;
		hRReal = 20;
		clutch = 1;

		tracking = false;
		trackingCoefficient = 0;

		passable = false;
		passableJump = false;
		passableSlide = false;
		passableCrouch = false;

		imageObject.loadFromFile("Environment/Objects/box.png");
		imageObject.createMaskFromColor(Color(255, 255, 255));					//Прозрачность белого
		textureObject.loadFromImage(imageObject);
		spriteObject.setTexture(textureObject);
		spriteObject.setTextureRect(IntRect(xM, yM, wM, hM));
		spriteObject.setPosition(xR, yR);										//Установка спрайта на позицию отрисовки
		layer = yRReal + hRReal;												//Установили слой первоначально
	}
};