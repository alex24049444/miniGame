#pragma once
#include "ClassNPCFriendly.h"
#include "ClassNPCFriendlyDBunny.h"
#include "ClassNPCFriendlyTalkingDWoman.h"
#include "ClassNPCEnemy.h"

using namespace std;

void DrawNPC(View, float, vector<vector<NPC*>>&, int);							//������������ ������������� NPC � ������������ � ���������� � ���������
void NPCLogic(float, vector<vector<NPC*>>&, int);								//������ ������������� NPC