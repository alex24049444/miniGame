#pragma once

#include <SFML/Graphics.hpp>
#include "ClassObject.h"

//Класс анимированных объектов 
//TODO: Разрешить все предупреждения
class ObjectAnim : public Object
{
protected:
	float animSpeed;					//Скорость анимации >0
	int frames;							//Кол-во кадров в анимации объекта
	float currentFrame = 0;				//Текущий кадр

public:
	ObjectAnim() {};

	void Draw(View) override;												//Установка спрайта в позицию на координатной сетке для отрисовки

	float Get_currentFrame() { return currentFrame; }						//Номер кадра
	float Get_animSpeed() { return animSpeed; }								//Получение скорости анимации
	int Get_frames() { return frames; }										//Возвращает количество кадров анимации

	void Set_currentFrame(float value) { currentFrame = value; }			//Установка текущего кадра
};