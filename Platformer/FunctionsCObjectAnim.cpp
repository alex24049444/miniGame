#include "ClassObjectAnim.h"

/*
Отрисовка включает:
1)Установку точки, с которой рисовать
2)Загрузку текстуры в спрайт
*/

void ObjectAnim::Draw(View view)
{
	if (tracking == true) {
		sf::Vector2f vector = view.getCenter();																				//Если объект "следящий"
		spriteObject.setPosition(xR + (vector.x - xR) / trackingCoefficient, yR + (vector.y - yR) / trackingCoefficient);	//Соответственно устанавливаем точку отрисовки основываясь на камере вида
	}
	else
	{
		if (animated == true || movableO == true) {																		//Если объект двигается или движим
			layer = yRReal + hRReal;
			xR = xRReal - xRRealInside;
			yR = yRReal - yRRealInside;
			spriteObject.setPosition(xR, yR);																			//Надо постоянно менять точку отрисовки
		}
	}
}

