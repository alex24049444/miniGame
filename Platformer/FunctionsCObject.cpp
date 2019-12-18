#include "ClassObject.h"

/*
Отрисовка для следящего объекта включает:
1)Установку точки, с которой рисовать
2)Загрузку текстуры в спрайт
3)Вырезание нужного элемента из спрайта TODO: нужно перенести
*/
void Object::Draw(View view) {	//TODO: Cделать разделение на 3 главных класса, обычный, движимый, анимированный и их производные: движимый анимированный и движимый обычный
	if (movableO == true) {
		layer = yRReal + hRReal;
		xR = xRReal - xRRealInside;
		yR = yRReal - yRRealInside;
		spriteObject.setPosition(xR, yR);
	}
}

//Установка объекта на слой для корректной последовательности отрисовки
/*void Object::DetermineLayer()
{
	if(animated==true)
	{
		layer = yRReal + hRReal;
	}
}*/
