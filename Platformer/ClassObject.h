#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

//Класс объектов
//TODO: Разрешить все предупреждения
class Object
{
protected:
	float xR;							//Положение модели на карте по Х
	float yR;							//Положение модели на карте по Y
	float xM;							//Точка X начала текстуры в файле
	float yM;							//Точка Y начала текстуры в файле
	float wM;							//Ширина текстуры
	float hM;							//Высота текстуры
	float xRReal;						//Положение физической модели на карте по Х
	float yRReal;						//Положение физической модели на карте по Y
	float xRRealInside;					//X реальной модели внутри виртуальной модели
	float yRRealInside;					//Y реальной модели внутри виртуальной модели
	float wRReal;						//Ширина физической модели
	float hRReal;						//Высота физической модели
	float clutch;						//Сцепление	1-нормальное <1-пониженное >1-повышенное
	float trackingCoefficient;			//Коэффициент слежения объекта >1
	signed int layer = 0;				//Слой на котором отрисовывается объект
	signed int layerSub = 0;			//Уменьшение слоя, для больших объектов.

	bool passable;						//Доступен ли объект для прохождения сквозь него вообще
	bool passableJump;					//Доступен ли объект для прохождения сквозь него прыжком
	bool passableSlide;					//Доступен ли объект для прохождения сквозь него скольжением
	bool passableCrouch;				//Доступен ли объект для прохождения сквозь него вприсяди
	bool crossable;						//Должен ли герой впринципе пересекать этот объект?
	bool tracking;						//Следящий объект
	bool visible;						//Видимость объекта
	bool animated;						//Необходимо каждый раз изменять положение в пространстве? Для оптимизации.
	bool movableO;						//Способны ли другие объекты передвигать этот объект?
	//bool rendered = false;				//Отрисован ли объект?

	//String filePath;
	Image imageObject;
	Texture textureObject;
	Sprite spriteObject;

public:
	Object() {};		//Конструктор по умолчанию

	virtual void Draw(View);						//Установка спрайта в позицию на координатной сетке для отрисовки

	virtual int Animation(float) { return 0; };		//Анимация для ClassObjectAnim

	void DetermineLayer();							//Установка слоя

	//Вспомогательные Get-Функции

	Sprite Get_Sprite() { return spriteObject; }	//Получение спрайта
	float Get_xR() { return xR; }					//Получение	модели на карте по Х
	float Get_yR() { return yR; }					//Получение	модели на карте по Y
	float Get_xM() { return xM; }					//Получение X начала текстуры
	float Get_yM() { return yM; }					//Получение Y начала текстуры
	float Get_wM() { return wM; }					//Получение ширины текстуры
	float Get_hM() { return hM; }					//Получение высоты текстуры
	float Get_xRReal() { return xRReal; }			//Получение X начала физической модели
	float Get_yRReal() { return yRReal; }			//Получение Y начала физической модели
	float Get_wRReal() { return wRReal; }			//Получение ширины физической модели
	float Get_hRReal() { return hRReal; }			//Получение высоты физической модели
	float Get_clutch() { return clutch; }			//Получение сцепления
	float Get_trackingCoefficient() { return trackingCoefficient; }			//Получение сцепления
	signed int Get_layer() { return layer; }								//Получение слоя на котором располагается объект
	bool Get_passable() { return passable; }				//Получение доступности прохождения сквозь объект
	bool Get_passableJump() { return passableJump; }		//Получение доступности прохождения сквозь объект прыжком
	bool Get_passableSlide() { return passableSlide; }		//Получение доступности прохождения сквозь объект скольжением
	bool Get_passableCrouch() { return passableCrouch; }	//Получение доступности прохождения сквозь объект присядом
	bool Get_crossable() { return crossable; }				//На одном пространстве с героем рисуется?
	//bool Get_rendered() { return rendered; }				//Отриcован уже объект?
	bool Get_tracking() { return tracking; }				//Следящий ли объект?
	bool Get_animated() { return animated; }				//Передвигается ли объект?
	bool Get_movableO() { return movableO; }				//Движим ли объект?

	//Вспомогательные Set-Функции

	void Set_layer(signed int value) { layer = value; }		//Установка слоя
	void Set_crossable(bool value) { crossable = value; }	//Установка возможности пересечения
	void Set_xRReal(float value) { xRReal = value; }		//Установить x реaльной модели
	void Set_yRReal(float value) { yRReal = value; }		//Установить y реaльной модели
	void Set_spritePosition(float x, float y) { spriteObject.setPosition(x, y); }	//Установить положение спрайта, необходимо за счет упрощения в draw
	//void Set_rendered(bool value) { rendered = value; }		//Установка рендера
};