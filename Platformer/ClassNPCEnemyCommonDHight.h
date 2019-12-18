#pragma once
#include "ClassNPCEnemyCommon.h"
class NPCEnemyCommonDHight :public NPCEnemyCommon
{
public:
	NPCEnemyCommonDHight(int _Map, float _X, float _Y, int _Health)
	{
		currentMap = _Map;
		xN = _X;
		yN = _Y;
		wN = 150;
		hN = 200;
		xNRealInside = 38;
		yNRealInside = 180;
		wNRealInside = 58;
		hNRealInside = 10;
		xNReal = xN + xNRealInside;
		yNReal = yN + yNRealInside;
		//HP
		healthN = _Health;

		//����������� �����
		File = "HightSprite.png";
		image.loadFromFile("Sprites/" + File);
		image.createMaskFromColor(Color(255, 255, 255));	//������������ ������
		texture.loadFromImage(image);						//��������
		sprite.setTexture(texture);							//������
		sprite.setTextureRect(IntRect(0, 0, wN, hN));		//�������� NPC
	};
	void Logic(float)override;
	int Respawn(float);//�������� �������
	//AFK	
	int IdleLeft(float);//������� ������
	int IdleRight(float);//������� �����
	int DieRight(float);//������� ����� ������
	//AFK end
	int MoveRight(float);//�������� ������
	int MoveLeft(float);//�������� �����	
	void Draw(float)override;
};

