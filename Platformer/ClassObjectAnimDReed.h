#pragma once
#include "ClassObjectAnim.h"

//������������� �����
class ObjectAnimReed :public ObjectAnim
{
public:
	ObjectAnimReed(float _xOnMap, float _yOnMap, bool _passable, bool _passableJump, bool _passableSlide, bool _passableCrouch, float _clutch) {
		animated = false;
		movableO = false;

		frames = 4;
		crossable = false;
		animSpeed = 0.0003;
		//TODO: ����� �������� ��������
		xR = _xOnMap;
		yR = _yOnMap;
		xM = 0;
		yM = 50;
		wM = 20;
		hM = 50;
		xRReal = 5;
		yRReal = 45;
		wRReal = 10;
		hRReal = 5;
		clutch = _clutch;

		tracking = false;
		trackingCoefficient = 0;

		passable = _passable;
		passableJump = _passableJump;
		passableSlide = _passableSlide;
		passableCrouch = _passableCrouch;

		imageObject.loadFromFile("Environment/Objects/Grass.png");

		imageObject.createMaskFromColor(Color(255, 255, 255));					//������������ ������
		textureObject.loadFromImage(imageObject);
		spriteObject.setTexture(textureObject);
		spriteObject.setTextureRect(IntRect(xM, yM, wM, hM));
		spriteObject.setPosition(xR, yR);										//��������� ��������� ������� �� ������� ���������
		layer = yRReal + hRReal;												//���������� ����
	}

	int Animation(float) override;
};

