#pragma once

#include "ClassNPCFriendlyTalking.h"

using namespace sf;

//Класс включающий в себя дружественного квестового NPC женщину

class NPCFriendlyTalkingWoman : public NPCFriendlyTalking {
public:
	NPCFriendlyTalkingWoman(int _Map, float _X, float _Y, int _Health) {
		movableN = false;

		//Положение на карте и в пространстве
		currentMap = _Map;
		xN = _X;
		yN = _Y;
		wN = 50;
		hN = 62;
		xNRealInside = 12;
		yNRealInside = 52;
		wNRealInside = 20;
		hNRealInside = 10;
		xNReal = xN + xNRealInside;
		yNReal = yN + yNRealInside;

		//Здоровье
		healthMaxN = _Health;
		healthN = _Health;

		//Логическая часть
		logicReaction = 0.005;

		//Графическая часть
		image.loadFromFile("Sprites/WomanSprite.png");
		image.createMaskFromColor(Color(255, 255, 255));	//Прозрачность белого
		texture.loadFromImage(image);						//Текстура
		sprite.setTexture(texture);							//Спрайт
		sprite.setTextureRect(IntRect(0, 0, wN, hN));		//Вырезаем NPC
		sprite.setPosition(xN, yN);							//Устанавливаем точку отрисовки
		//layerN = yN + hN;
		layerN = trunc(yNReal + hNRealInside)-1;			//Установили слой навсегда -1 из-за double
	};
	
	void Logic(float) override;								//Функция логики для женщины, определяет, какое действие будет производиться

	//AFK

	int WomanIdleRight(float time);		//Бездействие вправо
	int WomanIdleLeft(float time);		//Бездействие влево
	
	void Draw(float) override;			//Перегруженная функция связи анимации и физики
};