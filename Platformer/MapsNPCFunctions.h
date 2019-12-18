#pragma once
#include "ClassNPCFriendly.h"
#include "ClassNPCFriendlyDBunny.h"
#include "ClassNPCFriendlyTalkingDWoman.h"
#include "ClassNPCEnemy.h"

using namespace std;

void DrawNPC(View, float, vector<vector<NPC*>>&, int);							//Расположение дружественных NPC в пространстве и подготовка к отрисовке
void NPCLogic(float, vector<vector<NPC*>>&, int);								//Логика дружественных NPC