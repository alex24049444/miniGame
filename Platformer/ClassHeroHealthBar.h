#pragma once

#include "ClassBar.h"

using namespace sf;

class HeroHealthBar : public Bar
{
public:
	HeroHealthBar()
	{
		/*Himage.loadFromFile("Sprites/Health.png");			//�������� ���������
		Htexture.loadFromImage(Himage);
		Hsprite.setTexture(Htexture);
		Hsprite.setTextureRect(IntRect(0,0,100,10));		
		
		DHtexture.loadFromImage(Himage);						//������� �������� ���������
		DHsprite.setTexture(DHtexture);
		DHsprite.setTextureRect(IntRect(2, 0, 1, 10));*/

		maxValue = 100;
		bar.setFillColor(Color(250, 50, 50));					//���� ���� ��������
		barN.setFillColor(Color(250, 170, 170));				//���� ���� ����������� ��������
		
	}

	void drawHealthBar(RenderWindow& window)
	{
		Vector2f center = window.getView().getCenter();
		Vector2f size = window.getView().getSize();

		//Hsprite.setPosition(center.x - size.x / 2 + 10, center.y - size.y / 2 + 10);
		bar.setPosition(center.x - size.x / 2 + 10, center.y - size.y / 2 + 10);
		barN.setPosition(center.x - size.x / 2 + 10 + maxValue, center.y - size.y / 2 + 10);

		//window.draw(Hsprite);
		window.draw(bar);
		window.draw(barN);
	}


};