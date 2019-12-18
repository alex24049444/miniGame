#include <random>
#include "OptimizedRandom.h"

using namespace std;

int RandomBetweenInt(int a, int b)
{
	random_device rd;						//������������������� ���������
	mt19937 gen(rd());						//��������� ������� ����� ��������
	uniform_int_distribution<> dist(a, b);	//������� ������ ��������� ����� a <= � <= b
	int c = dist(gen);						//���������
	return c;
}

double RandomBetweenDouble(double a, double b)
{
	random_device rd;						//������������������� ���������
	mt19937 gen(rd());						//��������� ������� ����� ��������
	uniform_real_distribution<> dist(a, b);	//������� ������ ��������� ����� a <= � <= b
	double c = dist(gen);					//���������
	return c;
}
