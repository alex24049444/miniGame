#pragma once
/*
Тут находятся объявления карт.
Одна карта - один массив.
Что дает карта:
	Объекты, и все их свойства
*/

#include <vector>
#include "ClassObject.h"
#include "ClassObjectDBox.h"
#include "ClassObjectDTree.h"
#include "ClassObjectAnimDGrass.h"
#include "ClassObjectAnimDReed.h"
#include "ClassObjectDMapFirst.h"
#include "ClassObjectAnimDMapUndFirstTrack.h"
#include "ClassObjectDWall.h"

using namespace std;
using namespace sf;

/*
Правила написания объектов на карту:
Первой всегда идет карта/карты, затем уже все объекты
Ширина и высота физической модели не должны быть меньше 5!
Визуальная составляющая объекта не всегда может совпадать с физической

vector[Номер карты на которой находится объект][Номер объекта][Количество кадров объекта]

Описание каждого объекта:
1) Должен ли персонаж впринципе пересекать физическую модель этого объекта
2) Скорость анимации
3) Файл из которого берется текстура
4) Положение модели на карте по Х
5) Положение модели на карте по Y
6) Точка X начала текстуры в файле
7) Точка Y начала текстуры в файле
8) Ширина текстуры вырезаемой из файла
9) Высота текстуры вырезаемой из файла
10) Нужна ли маска для текстуры (сделать белый цвет прозрачным)
11) Положение физической модели в текстуре по Х
12) Положение физической модели в текстуре по Y
13) Ширина физической в текстуре модели
14) Высота физической в текстуре модели
15) true-Объект пересекается любым способом
16) true-Объект пересекается любым прыжком
17) true-Объект пересекается скольжением
18) true-Объект пересекается вприсяди
19) Сцепление внутри физической модели объекта, чтобы имело смысл стоит поставить в true 14||15||16||17||18
20) Является ли объект "следящим"?
21) Коэффициент "слежения"

Примеры можно найти в массиве;
*/
/*
vector <vector <vector <Object> > > v = {
	//Карта № 1
	{
		{Object(true, false, 0.0003, "Objects/Grass.png", 1850, 770, 0, 50, 20, 50, true , 5, 45, 10, 5, true, false, false,false, 1, false, 0, 0),					//0.15.0
			Object(true, false, 0.0003, "Objects/Grass.png", 1850, 770, 20, 50, 20, 50, true , 5, 45, 10, 5, true, false, false,false, 1, false, 0, 0),					//0.15.1
			Object(true, false, 0.0003, "Objects/Grass.png", 1850, 770, 40, 50, 20, 50, true , 5, 45, 10, 5, true, false, false,false, 1, false, 0, 0),					//0.15.2
			Object(true, false, 0.0003, "Objects/Grass.png", 1850, 770, 60, 50, 20, 50, true , 5, 45, 100, 5, true, false, false,false, 1, false, 0, 0)},				//0.15.3
		{Object(true, false, 0.0003, "Objects/Grass.png", 2000, 790, 0, 50, 20, 50, true , 5, 45, 10, 5, true, false, false,false, 1, false, 0, 0),					//0.16.0
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 790, 20, 50, 20, 50, true , 5, 45, 10, 5, true, false, false,false, 1, false, 0, 0),					//0.16.1
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 790, 40, 50, 20, 50, true , 5, 45, 10, 5, true, false, false,false, 1, false, 0, 0),					//0.16.2
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 790, 60, 50, 20, 50, true , 5, 45, 100, 5, true, false, false,false, 1, false, 0, 0)},				//0.16.3
	}
	//Карта № 2
};*/


/*
Правила написания объектов на карту:
Первой всегда идет карта/карты, затем уже все объекты
Ширина и высота физической модели не должны быть меньше 5!
Визуальная составляющая объекта не всегда может совпадать с физической

vector[Номер карты на которой находится объект][Номер объекта]

Описание каждого объекта:
1) Положение модели на карте по Х
2) Положение модели на карте по Y
3) true-Объект пересекается любым способом
4) true-Объект пересекается любым прыжком
5) true-Объект пересекается скольжением
6) true-Объект пересекается вприсяди
7) Сцепление внутри физической модели объекта, чтобы имело смысл стоит поставить в true 14||15||16||17||18

Примеры можно найти в массиве;
*/
vector <vector <Object*>>  vMaps = {
	//Карта №1
	{
		new ObjectTrackMapUndFirst(),
		new ObjectMapFirst(),
		new ObjectWall(890, 470, 500, 20),
		new ObjectBox(1300, 500),
		new ObjectBox(1325, 500),
		new ObjectBox(1350, 500),
		new ObjectBox(920, 520),
		new ObjectBox(920, 540),
		new ObjectTree(1700, 330, false, true, false, false, 1),
		new ObjectTree(1750, 350, false, false, true, false, 1),
		new ObjectTree(1800, 340, false, false, false, true, 1),
		new ObjectTree(1550, 360, false, false, false, true, 1),
		new ObjectAnimGrass(1800, 800, true, false, false,false, 1),
		new ObjectAnimGrass(1900, 815, true, false, false,false, 1),
		new ObjectAnimGrass(1900, 830, true, false, false,false, 1),
		new ObjectAnimGrass(2000, 800, true, false, false,false, 1),
		new ObjectAnimGrass(2000, 815, true, false, false,false, 1),
		new ObjectAnimGrass(2000, 830, true, false, false,false, 1),
		new ObjectAnimGrass(1850, 770, true, false, false,false, 1),
		new ObjectAnimGrass(2000, 790, true, false, false,false, 1),
		//Камыш
		new ObjectAnimReed(1500,800,true,false,false,false,1)
	}
};