#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
//TODO: ��������� ��� ��������������
class Bar
{
protected:
	int maxValue;						//������������ �������� ����
	RectangleShape bar;					//��� ���������� �������� �������
	RectangleShape barN;				//��� ���������� ���������� �������
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