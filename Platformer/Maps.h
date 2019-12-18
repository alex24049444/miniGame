#pragma once
/*
��� ��������� ���������� ����.
���� ����� - ���� ������.
��� ���� �����:
	�������, � ��� �� ��������
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
������� ��������� �������� �� �����:
������ ������ ���� �����/�����, ����� ��� ��� �������
������ � ������ ���������� ������ �� ������ ���� ������ 5!
���������� ������������ ������� �� ������ ����� ��������� � ����������

vector[����� ����� �� ������� ��������� ������][����� �������][���������� ������ �������]

�������� ������� �������:
1) ������ �� �������� ��������� ���������� ���������� ������ ����� �������
2) �������� ��������
3) ���� �� �������� ������� ��������
4) ��������� ������ �� ����� �� �
5) ��������� ������ �� ����� �� Y
6) ����� X ������ �������� � �����
7) ����� Y ������ �������� � �����
8) ������ �������� ���������� �� �����
9) ������ �������� ���������� �� �����
10) ����� �� ����� ��� �������� (������� ����� ���� ����������)
11) ��������� ���������� ������ � �������� �� �
12) ��������� ���������� ������ � �������� �� Y
13) ������ ���������� � �������� ������
14) ������ ���������� � �������� ������
15) true-������ ������������ ����� ��������
16) true-������ ������������ ����� �������
17) true-������ ������������ �����������
18) true-������ ������������ ��������
19) ��������� ������ ���������� ������ �������, ����� ����� ����� ����� ��������� � true 14||15||16||17||18
20) �������� �� ������ "��������"?
21) ����������� "��������"

������� ����� ����� � �������;
*/
/*
vector <vector <vector <Object> > > v = {
	//����� � 1
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
	//����� � 2
};*/


/*
������� ��������� �������� �� �����:
������ ������ ���� �����/�����, ����� ��� ��� �������
������ � ������ ���������� ������ �� ������ ���� ������ 5!
���������� ������������ ������� �� ������ ����� ��������� � ����������

vector[����� ����� �� ������� ��������� ������][����� �������]

�������� ������� �������:
1) ��������� ������ �� ����� �� �
2) ��������� ������ �� ����� �� Y
3) true-������ ������������ ����� ��������
4) true-������ ������������ ����� �������
5) true-������ ������������ �����������
6) true-������ ������������ ��������
7) ��������� ������ ���������� ������ �������, ����� ����� ����� ����� ��������� � true 14||15||16||17||18

������� ����� ����� � �������;
*/
vector <vector <Object*>>  vMaps = {
	//����� �1
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
		//�����
		new ObjectAnimReed(1500,800,true,false,false,false,1)
	}
};