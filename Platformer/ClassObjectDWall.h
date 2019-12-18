#pragma once
#include "ClassObject.h"

//
class ObjectWall :public Object
{
public:
	ObjectWall(float _xOnMap, float _yOnMap, float _wRealOnMap, float _hRealOnMap) {
		crossable = true;
		movableO = false;

		xR = _xOnMap;
		yR = _yOnMap;
		xM = 0;
		yM = 0;
		wM = 0;
		hM = 0;
		xRReal = _xOnMap ;
		yRReal = _yOnMap ;
		wRReal = _wRealOnMap;
		hRReal = _hRealOnMap;
		clutch = 1;

		tracking = false;
		trackingCoefficient = 0;

		passable = false;
		passableJump = false;
		passableSlide = false;
		passableCrouch = false;

		imageObject.loadFromFile("");
		spriteObject.setPosition(xR, yR);										//Установка спрайта на позицию отрисовки
		layer = yRReal + hRReal;												//Установили слой навсегда
	}
};

