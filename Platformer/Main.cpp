/*
Main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
Работаем с библиотекой SFML.
Библиотеки встроенные-сверху, пользовательские файлы .h и.т.д. - снизу.
Соблюдайте "лесенку", используя как отступы TAB.
Все переменные только с маленькой буквы, все функции с большой буквы!
	Пример: xHero - переменная отвечающая за положение героя по х. MoveHero - функция отвечающая за передвижение героя.
Добавляйте как можно больше комментариев, большие пишутся по типу:
	//Комментарий описывающий КОД
	КОД
Малые:
	КОД			//Комментарий описывающий КОД

Условные обозначения:(дополняемо)
	ТЕХН-Техническая функция/библиотека, нужна для отладки и не используется в конечной программе.

	GL HF
*/
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")			//Отключение консоли

#include <conio.h>
#include "Pillars.h"
//Контроль персонажа
#include "ControlsCHero.h"
#include "ClassNPCEnemyCommonDLight.h"
#include "ClassHero.h"
//Карты
#include "Maps.h"
#include "MapsNPC.h"
#include "MapsNPCFunctions.h"
#include "MapsFunctions.h"
//Интерфейс
#include "ViewsAndWindow.h"
#include "ClassHeroHealthBar.h"
#include "ClassHeroStaminaBar.h"

using namespace sf;


//ТЕХH функция вывода значений из класса на экран
//Чтобы ей воспользоваться необходимо в main поставить комментарий на #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
/*void ConsoleCheck(Hero MainHero, float time, bool timecheck, bool speedXH, bool speedHY, bool cooldownJump, bool cooldownSlide, bool comboTimer)		
{
	if (timecheck == true) std::cout << time << "|";												//Вывод времени
	if (speedXH == true)std::cout << MainHero.Get_speedXH() << "|";									//Вывод скорости по Х
	if (speedHY == true)std::cout << MainHero.Get_speedXY() << "|";									//Вывод скорости по Y
	if (cooldownJump == true)std::cout << MainHero.Get_cooldownAnimationJump() << "|";				//Вывод кулдауна прыжка
	if (cooldownSlide == true)std::cout << MainHero.Get_cooldownAnimationSlide() << "|";			//Вывод кулдауна скольжения
	if (cooldownSlide == true)std::cout << MainHero.Get_cooldownAnimationSlide() << "|";			//Вывод кулдауна скольжения
	if (comboTimer == true) std::cout << MainHero.Get_comboTimer() << "|";							//Вывок времени на комбо
}*/

int main() {

	RenderWindow window(VideoMode(1280, 720), "Test");									//Рендер окна
	//window.setFramerateLimit(60);														//Ограничение FPS
	//window.setVerticalSyncEnabled(true);												//Ограничение FPS=60

	View MainView;																		//Рендер камеры вида
	Hero MainHero(1100, 500, 200, 100);													//Создаем героя
	HeroHealthBar healthBar;															//Создаем бар здоровья
	HeroStaminaBar staminaBar;															//Создаем бар выносливости
	MainView.reset(FloatRect(0,0,1280,720));											//Установка камеры вида на герое

	Clock clock;													//Создаем переменную времени, т.е. привязка ко времени(а не загруженности/мощности процессора).	
	
	float time;
	float stime = 0;																		
	

	//SetLayers(v, v[MainHero.Get_currentMap()].size(), MainHero.Get_currentMap());							//Распределение объектов по слоям
	while (window.isOpen())											//Выполняем пока окно открыто
	{
		time = clock.getElapsedTime().asMicroseconds();				//Получаем прошедшее время в микросекундах
		clock.restart();											//Перезагружаем часы
		time = time / 800;											//Скорость игры
		stime += time;												//Второй таймер
		
		//ConsoleCheck(MainHero,time, false, true,false,false,false,false);//ТЕХН, вывод значений из класса в консоль !!!КОММЕНТИРОВАТЬ,ЕСЛИ НЕ ИСПОЛЬЗУЕТСЯ, ТК ЗАМЕДЛЯЕТ ВРЕМЯ!!!

		Event event;
		while (window.pollEvent(event))																		//Событие закрытия окна
		{
			if (event.type == Event::Closed)
				window.close();
		}


		healthBar.updateBar(MainHero.Get_healthH(), MainHero.Get_healthMaxH(),10);							//ИНТЕРФЕЙС Бар здоровья
		staminaBar.updateBar(MainHero.Get_staminaH(), MainHero.Get_staminaMaxH(), 10);						//ИНТЕРФЕЙС Бар выносливости
		
		ControlsMainCharacter(MainHero,time,stime);															//Управление главным персонажем

		ViewXYfromClassHero(MainView, MainHero.Get_XHReal(), MainHero.Get_YHReal());						//Поддержание центра вида на персонаже

		NPCLogic(time, vNPC, MainHero.Get_currentMap());													//Логика NPC

		IntersectionObjectsAndNPCs(MainHero, vMaps, vNPC);													//Пересечение с объектами окружения всех объектов, NPC, итд.

		DrawNPC(MainView, time, vNPC, MainHero.Get_currentMap());											//Подготовка к отрисовке NPC
		DrawEnvironment(MainView, time, vMaps, MainHero.Get_currentMap());									//Подготовка к отрисовке объектов
		MainHero.Draw(time);																				//Подготовка к отрисовке персонажа
		
		window.setView(MainView);
		window.clear();																						//Очистка окна от предыдущего спрайта
		
		SpritesObjectsAndNPCs(window, MainHero, vMaps, vNPC);												//Отрисовка на карту
		
		healthBar.drawHealthBar(window);																	//ИНТЕРФЕЙС Бар здоровья
		staminaBar.drawStaminaBar(window);																	//ИНТЕРФЕЙС Бар выносливости
		window.display();																					//Отображение


	}

	//Очистка памяти из под vNPC
	for (auto i = 0; i < vNPC.size(); i++) {
		for (auto j = 0; j < vNPC[i].size(); j++) {
			delete vNPC[i][j];
		}
	}

	//Очистка памяти из под vMaps
	for (auto i = 0; i < vMaps.size(); i++) {
		for (auto j = 0; j < vMaps[i].size(); j++) {
			delete vMaps[i][j];
		}
	}

	return 0;
}




