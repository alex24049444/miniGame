#pragma once

#include "ClassBar.h"

using namespace sf;

class HeroStaminaBar:public Bar
{
public:
	HeroStaminaBar()
	{	
		maxValue = 100;
		bar.setFillColor(Color(10, 140, 10));					//÷вет бара выносливости
		barN.setFillColor(Color(170, 250, 170));				//÷вет бара потер€нной выносливости
	}

	void drawStaminaBar(RenderWindow& window)
{
	Vector2f center = window.getView().getCenter();
	Vector2f size = window.getView().getSize();

	bar.setPosition(center.x - size.x / 2 + 15, center.y - size.y / 2 + 17);
	barN.setPosition(center.x - size.x / 2 + 15 + maxValue, center.y - size.y / 2 + 17);

	window.draw(bar);
	window.draw(barN);
}

};

