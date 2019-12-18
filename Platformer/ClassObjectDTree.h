#pragma once

#include "ClassObject.h"

//Класс дерева
class ObjectTree : public Object {
public:
	ObjectTree(float _xOnMap, float _yOnMap, bool _passable, bool _passableJump, bool _passableSlide, bool _passableCrouch, float _clutch) {
		crossable = true;
		movableO = false;

		xR = _xOnMap;
		yR = _yOnMap;
		xM = 0;
		yM = 0;
		wM = 167;
		hM = 210;
		xRRealInside = 71;
		yRRealInside = 162;
		xRReal = _xOnMap + xRRealInside;
		yRReal = _yOnMap + yRRealInside;
		wRReal = 35;
		hRReal = 35;
		clutch = _clutch;

		tracking = false;
		trackingCoefficient = 0;

		passable = _passable;
		passableJump = _passableJump;
		passableSlide = _passableSlide;
		passableCrouch = _passableCrouch;

		imageObject.loadFromFile("Environment/Objects/Tree.png");
		imageObject.createMaskFromColor(Color(255, 255, 255));					//Прозрачность белого
		textureObject.loadFromImage(imageObject);
		spriteObject.setTexture(textureObject);
		spriteObject.setTextureRect(IntRect(xM, yM, wM, hM));
		spriteObject.setPosition(xR, yR);										//Установка спрайта на позицию отрисовки
		layerSub = 25;
		layer = yRReal + hRReal - layerSub;										//Установили слой навсегда
	}
};