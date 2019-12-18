#include "Math.h"
#include "MapsFunctions.h"

using namespace std;

void DrawEnvironment(View view, float time, vector< vector< Object*> > v, int currentMap) {
	for (int i = 0; i < v[currentMap].size(); i++)
	{
		v[currentMap][i]->Animation(time);												//Вырезание нужных кадров для анимации
		v[currentMap][i]->Draw(view);													//Подготовка к отрисовке
	}
}