#pragma once

#include "ClassNPCFriendly.h"

using namespace sf;

//����� ���������� � ���� �������������� ����������� NPC �������

class NPCFriendlyBunny : public NPCFriendly
{
public:
	NPCFriendlyBunny(int _Map, float _X, float _Y, int _Health) {
		movableN = true;

		//��������� �� ����� � � ������������
		currentMap = _Map;
		xN = _X;
		yN = _Y;
		wN = 35;
		hN = 35;
		xNRealInside = 0;
		yNRealInside = 10;
		wNRealInside = 35;
		hNRealInside = 25;
		xNReal = xN + xNRealInside;
		yNReal = yN + yNRealInside;
		speedNX = 0;
		speedNY = 0;

		//��������
		healthMaxN = _Health;
		healthN = _Health;

		//���������� �����
		logicReaction = 0.005;

		//����������� �����
		image.loadFromFile("Sprites/BunnySprite.png");
		image.createMaskFromColor(Color(255, 255, 255));	//������������ ������
		texture.loadFromImage(image);						//��������
		sprite.setTexture(texture);							//������
		sprite.setTextureRect(IntRect(0, 0, wN, hN));		//�������� NPC
	}

	void Logic(float) override;								//������� ������ ��� �������, ����������, ����� �������� ����� �������������

	int BunnyMoveRight(float);	//������ ��������� ������
	int BunnyMoveLeft(float);	//������ ��������� �����
	int BunnyMoveTop(float);	//������ ��������� �����
	int BunnyMoveDown(float);	//������ ��������� ����
	int BunnyEatRight(float);	//������ ��� ������
	int BunnyEatLeft(float);	//������ ��� �����
	int BunnyEatTop(float);		//������ ��� �����
	int BunnyEatDown(float);	//������ ��� ����
};

