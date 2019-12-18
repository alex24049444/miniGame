//Данный файл определяет функции, которые необходимы для связывания объектов в игре

#include "Pillars.h"
#include "EngineIntersection.h"
#include "ClassNPCEnemyCommonDLight.h"

void SpritesObjectsAndNPCs(RenderWindow& window, Hero h, vector<vector<Object*>> vO, vector<vector<NPC*>> vN)				//Все объекты поэтапно рисуются на свои слои
{
	for (int layer = 0; layer < 10000; layer++)																				//Пробегаемся по слоям
	{
		if (h.Get_layerH() == layer) { window.draw(h.Get_Sprite()); }														//Если нашли совпадение по слою выполняется вывод на экран с помощью SFML

		for (int i = 0; i < vO[h.Get_currentMap()].size(); i++)
		{
			if (vO[h.Get_currentMap()][i]->Get_layer() == layer) { window.draw(vO[h.Get_currentMap()][i]->Get_Sprite()); }
		}
		for (int j = 0; j < vN[h.Get_currentMap()].size(); j++)
		{
			if (vN[h.Get_currentMap()][j]->Get_layerN() == layer) { window.draw(vN[h.Get_currentMap()][j]->Get_Sprite()); }
		}
	}
}

void IntersectionObjectsAndNPCs(Hero &h, vector<vector<Object*>> &vO, vector<vector<NPC*>> &vN)						//Проверяется пересечение всех объектов в игре
{
	//ИГРОК--ОБЪЕКТ
	for (int i = 0; i < vO[h.Get_currentMap()].size(); i++)
	{
		int dir = 0;
		double value = 0;
		bool changeAviable = true;																								//Выполняем изменение
		//Проверка взаимодействия игрока и объекта
		tie(dir, value) = Intersection(h.Get_XHReal(), h.Get_YHReal(), h.Get_WHRealInside(), h.Get_HHRealInside(), vO[h.Get_currentMap()][i]->Get_xRReal(), vO[h.Get_currentMap()][i]->Get_yRReal(), vO[h.Get_currentMap()][i]->Get_wRReal(), vO[h.Get_currentMap()][i]->Get_hRReal());
		if (value != 0)
		{
			h.Set_clutchObj(vO[h.Get_currentMap()][i]->Get_clutch());																//Установили показатель сцепления

			if (vO[h.Get_currentMap()][i]->Get_passable() == true) changeAviable = false;											//Не выполняем изменение если объект вприницпе проходим
			if (h.Get_jumpAviable() == true && vO[h.Get_currentMap()][i]->Get_passableJump() == true) changeAviable = false;		//Не выполняем изменение если объект проходим прыжком
			if (h.Get_jumpLargeAviable() == true && vO[h.Get_currentMap()][i]->Get_passableJump() == true) changeAviable = false;	//Не выполняем изменение если объект проходим мощным прыжком
			if (h.Get_slideAviable() == true && vO[h.Get_currentMap()][i]->Get_passableSlide() == true) changeAviable = false;		//Не выполняем изменение если объект проходим скольжением
			if (h.Get_crouchAviable() == true && vO[h.Get_currentMap()][i]->Get_passableCrouch() == true) changeAviable = false;	//Не выполняем изменение если объект проходим вприсяди
			if (vO[h.Get_currentMap()][i]->Get_movableO() == true) changeAviable = false;											//Не выполняем изменение если объект можно сдвинуть

			if (changeAviable == true)														//Если все-таки изменяем положение игрока
			{
				if (dir == 1 || dir == 3)
				{
					h.Set_XHReal(value);
				}
				if (dir == 2 || dir == 4)
				{
					h.Set_YHReal(value);
				}
			}
			tie(dir, value) = Intersection(vO[h.Get_currentMap()][i]->Get_xRReal(), vO[h.Get_currentMap()][i]->Get_yRReal(), vO[h.Get_currentMap()][i]->Get_wRReal(), vO[h.Get_currentMap()][i]->Get_hRReal(), h.Get_XHReal(), h.Get_YHReal(), h.Get_WHRealInside(), h.Get_HHRealInside());
			if (vO[h.Get_currentMap()][i]->Get_movableO() == true)	//Если все-таки изменяем положение объекта
			{
				//Подвинули спрайт NOTE: ЕСЛИ movableO=true ВЕРНУТЬ В DRAW spriteObject.setPosition
				if (dir == 1 || dir == 3)
				{
					vO[h.Get_currentMap()][i]->Set_xRReal(value);
				}
				if (dir == 2 || dir == 4)
				{
					vO[h.Get_currentMap()][i]->Set_yRReal(value);
				}
			}
		}
	}

	//ИГРОК--NPC
	for (int i = 0; i < vN[h.Get_currentMap()].size(); i++)
	{
		int dir = 0;
		double value = 0;
		if (vN[h.Get_currentMap()][i]->rectM.intersects(h.rectH)) { vN[h.Get_currentMap()][i]->patrolmod = true;/*vN[h.Get_currentMap()][i]->patrolmod = true;*/ };
		//Проверка взаимодействия игрока и NPC
		if (vN[h.Get_currentMap()][i]->Get_movableN() == false) 
		{
			tie(dir, value) = Intersection(h.Get_XHReal(), h.Get_YHReal(), h.Get_WHRealInside(), h.Get_HHRealInside(), vN[h.Get_currentMap()][i]->Get_xNReal(), vN[h.Get_currentMap()][i]->Get_yNReal(), vN[h.Get_currentMap()][i]->Get_wNRealInside(), vN[h.Get_currentMap()][i]->Get_hNRealInside());

			if (dir == 1 || dir == 3)
			{
				h.Set_XHReal(value);
			}
			if (dir == 2 || dir == 4)
			{
				h.Set_YHReal(value);
			}
		}
		//Проверка взаимодействия NPC и игрока
		if (vN[h.Get_currentMap()][i]->Get_movableN() == true) 
		{
			tie(dir, value) = Intersection(vN[h.Get_currentMap()][i]->Get_xNReal(), vN[h.Get_currentMap()][i]->Get_yNReal(), vN[h.Get_currentMap()][i]->Get_wNRealInside(), vN[h.Get_currentMap()][i]->Get_hNRealInside(), h.Get_XHReal(), h.Get_YHReal(), h.Get_WHRealInside(), h.Get_HHRealInside());
			if (dir == 1 || dir == 3)
			{
				vN[h.Get_currentMap()][i]->Set_xNReal(value);
			}
			if (dir == 2 || dir == 4)
			{
				vN[h.Get_currentMap()][i]->Set_yNReal(value);
			}
		}
	}
	//ОБЪЕКТ--ОБЪЕКТ
	
	
	for (int i = 0; i < vO[h.Get_currentMap()].size(); i++)
	{
		for (int j = 0; j < vO[h.Get_currentMap()].size(); j++)
		{
			if (i != j) 
			{
				bool checkAviable = true;																									//Выполняем проверку
				if (vO[h.Get_currentMap()][i]->Get_passable() == true) checkAviable = false;												//Не выполняем проверку если i объект вприницпе проходим
				if (vO[h.Get_currentMap()][j]->Get_passable() == true) checkAviable = false;												//Не выполняем проверку если j объект вприницпе проходим

		        if (checkAviable == true) {	//Если все-таки выполняем выполняем проверку на пересечение
					int dir = 0;
					double value = 0;

					//Проверка взаимодействия объекта и объекта
					if (vO[h.Get_currentMap()][i]->Get_movableO() == true) {																//Если первый объект способен менять положение в пространстве
						tie(dir, value) = Intersection(vO[h.Get_currentMap()][i]->Get_xRReal(), vO[h.Get_currentMap()][i]->Get_yRReal(), vO[h.Get_currentMap()][i]->Get_wRReal(), vO[h.Get_currentMap()][i]->Get_hRReal(), vO[h.Get_currentMap()][j]->Get_xRReal(), vO[h.Get_currentMap()][j]->Get_yRReal(), vO[h.Get_currentMap()][j]->Get_wRReal(), vO[h.Get_currentMap()][j]->Get_hRReal());
						if (dir == 1 || dir == 3)
						{
							//Подвинули спрайт NOTE: ЕСЛИ movableO=true ВЕРНУТЬ В DRAW spriteObject.setPosition
							vO[h.Get_currentMap()][i]->Set_xRReal(value);
						}
						if (dir == 2 || dir == 4)
						{
							//Подвинули спрайт NOTE: ЕСЛИ movableO=true ВЕРНУТЬ В DRAW spriteObject.setPosition
							vO[h.Get_currentMap()][i]->Set_yRReal(value);
						}
					}
					if (vO[h.Get_currentMap()][j]->Get_movableO() == true) {																//Если второй объект способен менять положение в пространстве
						tie(dir, value) = Intersection(vO[h.Get_currentMap()][j]->Get_xRReal(), vO[h.Get_currentMap()][j]->Get_yRReal(), vO[h.Get_currentMap()][j]->Get_wRReal(), vO[h.Get_currentMap()][j]->Get_hRReal(), vO[h.Get_currentMap()][i]->Get_xRReal(), vO[h.Get_currentMap()][i]->Get_yRReal(), vO[h.Get_currentMap()][i]->Get_wRReal(), vO[h.Get_currentMap()][i]->Get_hRReal());
						if (dir == 1 || dir == 3)
						{
							//Подвинули спрайт NOTE: ЕСЛИ movableO=true ВЕРНУТЬ В DRAW spriteObject.setPosition
							vO[h.Get_currentMap()][j]->Set_xRReal(value);
						}
						if (dir == 2 || dir == 4)
						{
							//Подвинули спрайт NOTE: ЕСЛИ movableO=true ВЕРНУТЬ В DRAW spriteObject.setPosition
							vO[h.Get_currentMap()][j]->Set_yRReal(value);
						}
					}
				}
			}
		}
	}
	//NPC--ОБЪЕКТ
	
	for (int i = 0; i < vN[h.Get_currentMap()].size(); i++)
	{
		for (int j = 0; j < vO[h.Get_currentMap()].size(); j++)
		{
			if(vO[h.Get_currentMap()][j]->Get_passable() == false)																		//Не выполняем проверку если объект вприницпе проходим
			{
				int dir = 0;
				double value = 0;
				//Проверка взаимодействия NPC и объекта
				if (vO[h.Get_currentMap()][j]->Get_movableO() == false) {
					tie(dir, value) = Intersection(vN[h.Get_currentMap()][i]->Get_xNReal(), vN[h.Get_currentMap()][i]->Get_yNReal(), vN[h.Get_currentMap()][i]->Get_wNRealInside(), vN[h.Get_currentMap()][i]->Get_hNRealInside(), vO[h.Get_currentMap()][j]->Get_xRReal(), vO[h.Get_currentMap()][j]->Get_yRReal(), vO[h.Get_currentMap()][j]->Get_wRReal(), vO[h.Get_currentMap()][j]->Get_hRReal());
					if (dir == 1 || dir == 3)
					{
						vN[h.Get_currentMap()][i]->Set_xNReal(value);
					}
					if (dir == 2 || dir == 4)
					{
						vN[h.Get_currentMap()][i]->Set_yNReal(value);
					}
				}
				//Проверка взаимодействия объекта и NPC 
				if (vO[h.Get_currentMap()][j]->Get_movableO() == true) { //Если объект способен менять положение в пространстве
					tie(dir, value) = Intersection(vO[h.Get_currentMap()][j]->Get_xRReal(), vO[h.Get_currentMap()][j]->Get_yRReal(), vO[h.Get_currentMap()][j]->Get_wRReal(), vO[h.Get_currentMap()][j]->Get_hRReal(), vN[h.Get_currentMap()][i]->Get_xNReal(), vN[h.Get_currentMap()][i]->Get_yNReal(), vN[h.Get_currentMap()][i]->Get_wNRealInside(), vN[h.Get_currentMap()][i]->Get_hNRealInside());
					if (dir == 1 || dir == 3)
					{
						vO[h.Get_currentMap()][j]->Set_xRReal(value);
					}
					if (dir == 2 || dir == 4)
					{
						vO[h.Get_currentMap()][j]->Set_yRReal(value);
					}
				}
			}
			if(vO[h.Get_currentMap()][j]->Get_passable() == true)																		//Выполняем проверку чтобы выставить сцепление объекта на котором стоит NPC
			{
				int dir = 0;
				double value = 0;
				tie(dir, value) = Intersection(vN[h.Get_currentMap()][i]->Get_xNReal(), vN[h.Get_currentMap()][i]->Get_yNReal(), vN[h.Get_currentMap()][i]->Get_wNRealInside(), vN[h.Get_currentMap()][i]->Get_hNRealInside(), vO[h.Get_currentMap()][j]->Get_xRReal(), vO[h.Get_currentMap()][j]->Get_yRReal(), vO[h.Get_currentMap()][j]->Get_wRReal(), vO[h.Get_currentMap()][j]->Get_hRReal());
				if (value != 0) 
				{
					vN[h.Get_currentMap()][i]->Set_clutchObj(vO[h.Get_currentMap()][j]->Get_clutch());
				}
			}
		}
	}
	//NPC--NPC

	for (int i = 0; i < vN[h.Get_currentMap()].size(); i++)
	{
		for (int j = 0; j < vN[h.Get_currentMap()].size(); j++)
		{
			if (i != j) 
			{
				int dir = 0;
				double value = 0;
				//Проверка взаимодействия NPC и NPC
				if (vN[h.Get_currentMap()][i]->Get_movableN() == true && vN[h.Get_currentMap()][j]->Get_movableN() == false)	//Первый NPC движим, второй NPC недвижим
				{
					tie(dir, value) = Intersection(vN[h.Get_currentMap()][i]->Get_xNReal(), vN[h.Get_currentMap()][i]->Get_yNReal(), vN[h.Get_currentMap()][i]->Get_wNRealInside(), vN[h.Get_currentMap()][i]->Get_hNRealInside(), vN[h.Get_currentMap()][j]->Get_xNReal(), vN[h.Get_currentMap()][j]->Get_yNReal(), vN[h.Get_currentMap()][j]->Get_wNRealInside(), vN[h.Get_currentMap()][j]->Get_hNRealInside());
					if (dir == 1 || dir == 3)
					{
						vN[h.Get_currentMap()][i]->Set_xNReal(value);
					}
					if (dir == 2 || dir == 4)
					{
						vN[h.Get_currentMap()][i]->Set_yNReal(value);
					}
				}
				if (vN[h.Get_currentMap()][i]->Get_movableN() == true && vN[h.Get_currentMap()][j]->Get_movableN() == true)	//Первый NPC движим и второй NPC движим
				{
					if(vN[h.Get_currentMap()][j]->Get_speedNX() != 0 || vN[h.Get_currentMap()][j]->Get_speedNY() != 0)		//Если второй NPC в данный момент не двигается
					{
						tie(dir, value) = Intersection(vN[h.Get_currentMap()][j]->Get_xNReal(), vN[h.Get_currentMap()][j]->Get_yNReal(), vN[h.Get_currentMap()][j]->Get_wNRealInside(), vN[h.Get_currentMap()][j]->Get_hNRealInside(), vN[h.Get_currentMap()][i]->Get_xNReal(), vN[h.Get_currentMap()][i]->Get_yNReal(), vN[h.Get_currentMap()][i]->Get_wNRealInside(), vN[h.Get_currentMap()][i]->Get_hNRealInside());
						if (dir == 1 || dir == 3)																			//Значит подвинем его
						{
							vN[h.Get_currentMap()][j]->Set_xNReal(value);
						}
						if (dir == 2 || dir == 4)
						{
							vN[h.Get_currentMap()][j]->Set_yNReal(value);
						}
					}
				}
			}
		}
	}
}