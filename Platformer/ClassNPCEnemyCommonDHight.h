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

		//Графическая часть
		File = "HightSprite.png";
		image.loadFromFile("Sprites/" + File);
		image.createMaskFromColor(Color(255, 255, 255));	//Прозрачность белого
		texture.loadFromImage(image);						//Текстура
		sprite.setTexture(texture);							//Спрайт
		sprite.setTextureRect(IntRect(0, 0, wN, hN));		//Вырезаем NPC
	};
	void Logic(float)override;
	int Respawn(float);//Движение Респавн
	//AFK	
	int IdleLeft(float);//Смотрит вправо
	int IdleRight(float);//Смотрит влево
	int DieRight(float);//Умирает лицом вправо
	//AFK end
	int MoveRight(float);//Движение вправо
	int MoveLeft(float);//Движение влево	
	void Draw(float)override;
};

