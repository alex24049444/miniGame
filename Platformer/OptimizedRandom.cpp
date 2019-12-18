#include <random>
#include "OptimizedRandom.h"

using namespace std;

int RandomBetweenInt(int a, int b)
{
	random_device rd;						//Недетерминированный генератор
	mt19937 gen(rd());						//Генерация методом вихря Мерсенна
	uniform_int_distribution<> dist(a, b);	//Задание границ генерации числа a <= с <= b
	int c = dist(gen);						//Генерация
	return c;
}

double RandomBetweenDouble(double a, double b)
{
	random_device rd;						//Недетерминированный генератор
	mt19937 gen(rd());						//Генерация методом вихря Мерсенна
	uniform_real_distribution<> dist(a, b);	//Задание границ генерации числа a <= с <= b
	double c = dist(gen);					//Генерация
	return c;
}
