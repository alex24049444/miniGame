#include <SFML/Graphics.hpp>
#include "EnginePhysics.h"

using namespace sf;

//ќпределени€ вспомогательных функций анимации дл€ главного геро€

/*
‘ункци€ воспроизведени€ анимации скольжени€,сначала воспроизводитс€ нециклическа€ анимаци€, затем циклическа€, затем снова не циклическа€ анимаци€
cooldown		-куладун скольжени€ увеличиваетс€ на значение cooldownValue
direction		-направление скольжени€
directionValue	-значение направлени€ —мотри "розу направлений"
currentFrameUN	-текущий кадр
time			-часы
animationSpeed	-скорость анимации
frames			-количество кадров в анимации
sprite			-спрайт
y2				-положение нижней точки по Y
x11				-нужен дл€ отражени€
aviable			-возвращает значение, выполн€етс€ ли еще эта анимаци€
fHX,sHX,fHY,SHY -ограничени€ скорости
msX,msY,clutchX,clutchY,clutchObj,addX,addY - нужны дл€ движка физики
*/

void OnlySlideAnimation(float& currentFrameUN, float time, float& cooldown, float cooldownValue, bool& avaible, int& direction, int directionValue, float& speedHX, float& speedHY, Sprite& sprite, int x11, int x2, float msX, float msY, float clutchX, float clutchY, float clutchObj, float addX, float addY, double fHX, double sHX, double fHY, double sHY) {
	cooldown += cooldownValue * time;
	direction = directionValue;
	currentFrameUN += 0.007 * time;
	bool minusFrames = false;
	if (currentFrameUN < 2) {
		sprite.setTextureRect(IntRect(100 * int(currentFrameUN) + x11, 592, x2, 74));
		//if (speedHX < (sHX + addX * time)) speedHX += addX * time;
		//if (speedHY < (sHY + addY * time)) speedHY += addY * time;
		speedHX += addX * time;
		speedHY += addY * time;
	}
	else {
		Physics(speedHX, speedHY, time, clutchObj, msX, msY, clutchX, clutchY, 0, 0);
		if (currentFrameUN > 2 && currentFrameUN < 4.1 && (speedHX > fHX && speedHX< sHX && speedHY> fHY && speedHY < sHY)) {
			if (Keyboard::isKeyPressed(Keyboard::C)) {
				if (currentFrameUN > 4) { currentFrameUN = 2.0; }
				sprite.setTextureRect(IntRect(100 * int(currentFrameUN) + x11, 592, x2, 74));
			}
			else currentFrameUN = 4.2;
		}
		else {
			if (currentFrameUN > 4.1) {
				sprite.setTextureRect(IntRect(100 * int(currentFrameUN) + x11, 592, x2, 74));
			}
			if (currentFrameUN > 8)
			{
				avaible = false;
				currentFrameUN = 0;
			}
		}
	}
}

/*
‘ункци€ воспроизведени€ анимации прыжка, полностью не циклическа€ анимаци€
cooldown		-куладун прыжка увеличиваетс€ на значение cooldownValue
direction		-направление прыжка
directionValue	-значение направлени€ —мотри "розу направлений"
currentFrameUN	-текущий кадр
time			-часы
animationSpeed	-скорость анимации
frames			-количество кадров в анимации
sprite			-спрайт
y1				-положение верхней точки по Y
y2				-положение нижней точки по Y
x11				-нужен дл€ отражени€
aviable			-возвращает значение, выполн€етс€ ли еще эта анимаци€
fHX,sHX,fHY,SHY -ограничени€ скорости
msX,msY,clutchX,clutchY,clutchObj,addX,addY - нужны дл€ движка физики
*/

void OnlyJumpsAnimation(float& currentFrameUN, float time, float& cooldown, float cooldownValue, bool& avaible, int& direction, int directionValue, double animationSpeed, float& speedHX, float& speedHY, Sprite& sprite, int x11, int y1, int x2, int frames, float msX, float msY, float clutchX, float clutchY, float clutchObj, float addX, float addY, double fHX, double sHX, double fHY, double sHY) {
	cooldown += cooldownValue * time;
	direction = directionValue;
	currentFrameUN += animationSpeed * time;
	if (speedHX > fHX&& speedHX< sHX && speedHY> fHY&& speedHY < sHY) {
		Physics(speedHX, speedHY, time, /*clutchObj*/ 1, msX, msY, clutchX, clutchY, addX, addY);
	}
	sprite.setTextureRect(IntRect(100 * int(currentFrameUN) + x11, y1, x2, 74));
	if (currentFrameUN > frames)
	{
		avaible = false;
		currentFrameUN = 0;
	}
}