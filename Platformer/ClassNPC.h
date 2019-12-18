#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

//Класс от которого наследуются все другие NPC
//TODO: Разрешить все предупреждения
class NPC {
protected:
	float xN=0;							//Положение виртуальной модели по х
	float yN=0;							//Положение виртуальной модели по y
	float wN=0;							//Ширина модели	для конструктора
	float hN=0;							//Высота модели для конструктора
	float xNReal=0;						//Х реальной модели внутри виртуальной модели относительной всей оси
	float yNReal=0;						//Y реальной модели внутри виртуальной модели относительной всей оси
	float xNRealInside=0;					//Х реальной модели внутри виртуальной модели
	float yNRealInside=0;					//Y реальной модели внутри виртуальной модели
	float wNRealInside=0;					//Ширина реальной модели внутри виртуальной модели
	float hNRealInside=0;					//Высота реальной модели внутри виртуальной модели

	float dxN = 0;						//Ускорение по х
	float dyN = 0;						//Ускорение по y
	float speedNX = 0;					//Скорость NPC по x
	float speedNY = 0;					//Скорость NPC по y

	float clutchObj = 1;				//Сцепление NPC с поверхностью на которой он стоит
	int dirN=0;							//Направление движения/взгляда
	int currentMap = 0;					//Текущая карта

	int healthN;						//Здоровье NPC
	int healthMaxN;
	
	String File;						//Файл с расширением
	Image image;						//Изображение
	Texture texture;					//Текстура
	Sprite sprite;						//Спрайт
	signed int layerN=0;					//Слой отрисовки

	float currentFrame = 0;				//Номер текущего кадра циклической анимации
	float currentUncycleFrame = 0;		//Номер текущего кадра не циклической анимации

	bool movableN=false;						//Способны ли другие объекты передвигать этого NPC?
public:
	bool patrolmod = false;				//Состояние патрулирования территории
	FloatRect rectM;
	NPC() {}

	//Get-функции
	FloatRect getRect() { return rectM; }; // получить прямоугольник

	Sprite Get_Sprite() { return sprite; }										//Получить Спрайт
	int Get_currentMap() { return currentMap; }									//Узнать на какой карте сейчас находимся
	int Get_healthN() { return healthN; }										//Узнать значение здоровья NPC
	int Get_healthMaxN() { return healthMaxN; }									//Узнать максимальное здоровье NPC
	signed int Get_layerN() { return layerN; }									//Получение слоя на котором располагается NPC
	float Get_xN() { return xN; }												//Получить положение виртуальной модели по х
	float Get_yN() { return yN; }												//Получить положение виртуальной модели по у
	float Get_wN() { return wN; }												//Получить ширину модели
	float Get_hN() { return hN; }												//Получить высоту модели
	float Get_xNReal() { return xNReal; }										//Получить положение реальной модели по оси х
	float Get_yNReal() { return yNReal; }										//Получить положение реальной модели по оси у
	float Get_xNRealInside() { return xNRealInside; }							//Получить х реальной модели
	float Get_yNRealInside() { return yNRealInside; }							//Получить y реальной модели
	float Get_wNRealInside() { return wNRealInside; }							//Получить ширину реальной модели
	float Get_hNRealInside() { return hNRealInside; }							//Получить высоту реальной модели
	float Get_clutchObj() { return clutchObj; }									//Получить величину сцепления NPC с поверхностью на которой он стоит
	float Get_speedNX() { return speedNX; }										//Получить скорость по х
	float Get_speedNY() { return speedNY; }										//Получить скорость по у
	bool Get_movableN() { return movableN; }									//Движим ли NPC?

	//Set-функции

	void Set_currentMap(int value) { currentMap = value; }						//Установить номер текущей карты
	void Set_healthN(int value) { healthN = value; }							//Установить текущее здоровье героя
	void Set_healthMaxN(int value) { healthMaxN = value; }						//Установить максимальное здоровье героя
	void Set_xN(float value) { xN = value; }									//Установить положение виртуальной модели по х
	void Set_yN(float value) { yN = value; }									//Установить положение виртуальной модели по у
	void Set_xNReal(float value) { xNReal = value; }							//Установить положение реальной модели по х
	void Set_yNReal(float value) { yNReal = value; }							//Установить положение реальной модели по у
	void Set_xNRealInside(float value) { xNRealInside = value; }				//Установить x реaльной модели
	void Set_yNRealInside(float value) { yNRealInside = value; }				//Установить y реaльной модели
	void Set_wNRealInside(float value) { wNRealInside = value; }				//Установить ширину реaльной модели
	void Set_hNRealInside(float value) { hNRealInside = value; }				//Установить высоту реaльной модели
	void Set_clutchObj(float value) { clutchObj = value; }						//Установить величину сцепления персонажа с поверхностью на которой он стоит
	void Set_layerN(signed int value) { layerN = value; }						//Установка слоя

	virtual void Draw(float);													//Связь физики и анимации
	virtual void Logic(float) {};												//Логика
	void SetRealSizeNPC(float, float, float, float);							//Изменение размеров внутренней модели
};