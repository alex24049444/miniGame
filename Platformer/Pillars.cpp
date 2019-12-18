//������ ���� ���������� �������, ������� ���������� ��� ���������� �������� � ����

#include "Pillars.h"
#include "EngineIntersection.h"
#include "ClassNPCEnemyCommonDLight.h"

void SpritesObjectsAndNPCs(RenderWindow& window, Hero h, vector<vector<Object*>> vO, vector<vector<NPC*>> vN)				//��� ������� �������� �������� �� ���� ����
{
	for (int layer = 0; layer < 10000; layer++)																				//����������� �� �����
	{
		if (h.Get_layerH() == layer) { window.draw(h.Get_Sprite()); }														//���� ����� ���������� �� ���� ����������� ����� �� ����� � ������� SFML

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

void IntersectionObjectsAndNPCs(Hero &h, vector<vector<Object*>> &vO, vector<vector<NPC*>> &vN)						//����������� ����������� ���� �������� � ����
{
	//�����--������
	for (int i = 0; i < vO[h.Get_currentMap()].size(); i++)
	{
		int dir = 0;
		double value = 0;
		bool changeAviable = true;																								//��������� ���������
		//�������� �������������� ������ � �������
		tie(dir, value) = Intersection(h.Get_XHReal(), h.Get_YHReal(), h.Get_WHRealInside(), h.Get_HHRealInside(), vO[h.Get_currentMap()][i]->Get_xRReal(), vO[h.Get_currentMap()][i]->Get_yRReal(), vO[h.Get_currentMap()][i]->Get_wRReal(), vO[h.Get_currentMap()][i]->Get_hRReal());
		if (value != 0)
		{
			h.Set_clutchObj(vO[h.Get_currentMap()][i]->Get_clutch());																//���������� ���������� ���������

			if (vO[h.Get_currentMap()][i]->Get_passable() == true) changeAviable = false;											//�� ��������� ��������� ���� ������ ��������� ��������
			if (h.Get_jumpAviable() == true && vO[h.Get_currentMap()][i]->Get_passableJump() == true) changeAviable = false;		//�� ��������� ��������� ���� ������ �������� �������
			if (h.Get_jumpLargeAviable() == true && vO[h.Get_currentMap()][i]->Get_passableJump() == true) changeAviable = false;	//�� ��������� ��������� ���� ������ �������� ������ �������
			if (h.Get_slideAviable() == true && vO[h.Get_currentMap()][i]->Get_passableSlide() == true) changeAviable = false;		//�� ��������� ��������� ���� ������ �������� �����������
			if (h.Get_crouchAviable() == true && vO[h.Get_currentMap()][i]->Get_passableCrouch() == true) changeAviable = false;	//�� ��������� ��������� ���� ������ �������� ��������
			if (vO[h.Get_currentMap()][i]->Get_movableO() == true) changeAviable = false;											//�� ��������� ��������� ���� ������ ����� ��������

			if (changeAviable == true)														//���� ���-���� �������� ��������� ������
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
			if (vO[h.Get_currentMap()][i]->Get_movableO() == true)	//���� ���-���� �������� ��������� �������
			{
				//��������� ������ NOTE: ���� movableO=true ������� � DRAW spriteObject.setPosition
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

	//�����--NPC
	for (int i = 0; i < vN[h.Get_currentMap()].size(); i++)
	{
		int dir = 0;
		double value = 0;
		if (vN[h.Get_currentMap()][i]->rectM.intersects(h.rectH)) { vN[h.Get_currentMap()][i]->patrolmod = true;/*vN[h.Get_currentMap()][i]->patrolmod = true;*/ };
		//�������� �������������� ������ � NPC
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
		//�������� �������������� NPC � ������
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
	//������--������
	
	
	for (int i = 0; i < vO[h.Get_currentMap()].size(); i++)
	{
		for (int j = 0; j < vO[h.Get_currentMap()].size(); j++)
		{
			if (i != j) 
			{
				bool checkAviable = true;																									//��������� ��������
				if (vO[h.Get_currentMap()][i]->Get_passable() == true) checkAviable = false;												//�� ��������� �������� ���� i ������ ��������� ��������
				if (vO[h.Get_currentMap()][j]->Get_passable() == true) checkAviable = false;												//�� ��������� �������� ���� j ������ ��������� ��������

		        if (checkAviable == true) {	//���� ���-���� ��������� ��������� �������� �� �����������
					int dir = 0;
					double value = 0;

					//�������� �������������� ������� � �������
					if (vO[h.Get_currentMap()][i]->Get_movableO() == true) {																//���� ������ ������ �������� ������ ��������� � ������������
						tie(dir, value) = Intersection(vO[h.Get_currentMap()][i]->Get_xRReal(), vO[h.Get_currentMap()][i]->Get_yRReal(), vO[h.Get_currentMap()][i]->Get_wRReal(), vO[h.Get_currentMap()][i]->Get_hRReal(), vO[h.Get_currentMap()][j]->Get_xRReal(), vO[h.Get_currentMap()][j]->Get_yRReal(), vO[h.Get_currentMap()][j]->Get_wRReal(), vO[h.Get_currentMap()][j]->Get_hRReal());
						if (dir == 1 || dir == 3)
						{
							//��������� ������ NOTE: ���� movableO=true ������� � DRAW spriteObject.setPosition
							vO[h.Get_currentMap()][i]->Set_xRReal(value);
						}
						if (dir == 2 || dir == 4)
						{
							//��������� ������ NOTE: ���� movableO=true ������� � DRAW spriteObject.setPosition
							vO[h.Get_currentMap()][i]->Set_yRReal(value);
						}
					}
					if (vO[h.Get_currentMap()][j]->Get_movableO() == true) {																//���� ������ ������ �������� ������ ��������� � ������������
						tie(dir, value) = Intersection(vO[h.Get_currentMap()][j]->Get_xRReal(), vO[h.Get_currentMap()][j]->Get_yRReal(), vO[h.Get_currentMap()][j]->Get_wRReal(), vO[h.Get_currentMap()][j]->Get_hRReal(), vO[h.Get_currentMap()][i]->Get_xRReal(), vO[h.Get_currentMap()][i]->Get_yRReal(), vO[h.Get_currentMap()][i]->Get_wRReal(), vO[h.Get_currentMap()][i]->Get_hRReal());
						if (dir == 1 || dir == 3)
						{
							//��������� ������ NOTE: ���� movableO=true ������� � DRAW spriteObject.setPosition
							vO[h.Get_currentMap()][j]->Set_xRReal(value);
						}
						if (dir == 2 || dir == 4)
						{
							//��������� ������ NOTE: ���� movableO=true ������� � DRAW spriteObject.setPosition
							vO[h.Get_currentMap()][j]->Set_yRReal(value);
						}
					}
				}
			}
		}
	}
	//NPC--������
	
	for (int i = 0; i < vN[h.Get_currentMap()].size(); i++)
	{
		for (int j = 0; j < vO[h.Get_currentMap()].size(); j++)
		{
			if(vO[h.Get_currentMap()][j]->Get_passable() == false)																		//�� ��������� �������� ���� ������ ��������� ��������
			{
				int dir = 0;
				double value = 0;
				//�������� �������������� NPC � �������
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
				//�������� �������������� ������� � NPC 
				if (vO[h.Get_currentMap()][j]->Get_movableO() == true) { //���� ������ �������� ������ ��������� � ������������
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
			if(vO[h.Get_currentMap()][j]->Get_passable() == true)																		//��������� �������� ����� ��������� ��������� ������� �� ������� ����� NPC
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
				//�������� �������������� NPC � NPC
				if (vN[h.Get_currentMap()][i]->Get_movableN() == true && vN[h.Get_currentMap()][j]->Get_movableN() == false)	//������ NPC ������, ������ NPC ��������
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
				if (vN[h.Get_currentMap()][i]->Get_movableN() == true && vN[h.Get_currentMap()][j]->Get_movableN() == true)	//������ NPC ������ � ������ NPC ������
				{
					if(vN[h.Get_currentMap()][j]->Get_speedNX() != 0 || vN[h.Get_currentMap()][j]->Get_speedNY() != 0)		//���� ������ NPC � ������ ������ �� ���������
					{
						tie(dir, value) = Intersection(vN[h.Get_currentMap()][j]->Get_xNReal(), vN[h.Get_currentMap()][j]->Get_yNReal(), vN[h.Get_currentMap()][j]->Get_wNRealInside(), vN[h.Get_currentMap()][j]->Get_hNRealInside(), vN[h.Get_currentMap()][i]->Get_xNReal(), vN[h.Get_currentMap()][i]->Get_yNReal(), vN[h.Get_currentMap()][i]->Get_wNRealInside(), vN[h.Get_currentMap()][i]->Get_hNRealInside());
						if (dir == 1 || dir == 3)																			//������ �������� ���
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