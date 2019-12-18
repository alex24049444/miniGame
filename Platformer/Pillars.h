#pragma once
//Данный файл предназначен для объявления функций, которые связывают все объекты в игре

#include <vector>
#include <SFML/Graphics.hpp>
#include "ClassHero.h"
#include "ClassObject.h"
#include "ClassNPCFriendly.h"

using namespace std;
using namespace sf;

void SpritesObjectsAndNPCs(RenderWindow&, Hero, vector<vector<Object*>>, vector<vector<NPC*>>);	//Все объекты поэтапно рисуются на свои слои

void IntersectionObjectsAndNPCs(Hero&, vector<vector<Object*>>&, vector<vector<NPC*>>&);		//Все объекты проверяются на столкновения.