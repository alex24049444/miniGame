#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
//TODO: Разрешить все предупреждения
class Bar
{
protected:
	int maxValue;						//Максимальное значение бара
	RectangleShape bar;					//Бар отражающий значение ресурса
	RectangleShape barN;				//Бар отражающий недостаток ресурса
public:
	Bar() {};

	void updateBar(int current, int max, int height) 
	{
		if (current > 0) {
			bar.setSize(Vector2f(max, height));
			barN.setSize(Vector2f(-(max - current), height));
			maxValue = max;
		}
	}
};