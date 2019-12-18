/*
Main.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
�������� � ����������� SFML.
���������� ����������-������, ���������������� ����� .h �.�.�. - �����.
���������� "�������", ��������� ��� ������� TAB.
��� ���������� ������ � ��������� �����, ��� ������� � ������� �����!
	������: xHero - ���������� ���������� �� ��������� ����� �� �. MoveHero - ������� ���������� �� ������������ �����.
���������� ��� ����� ������ ������������, ������� ������� �� ����:
	//����������� ����������� ���
	���
�����:
	���			//����������� ����������� ���

�������� �����������:(����������)
	����-����������� �������/����������, ����� ��� ������� � �� ������������ � �������� ���������.

	GL HF
*/
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")			//���������� �������

#include <conio.h>
#include "Pillars.h"
//�������� ���������
#include "ControlsCHero.h"
#include "ClassNPCEnemyCommonDLight.h"
#include "ClassHero.h"
//�����
#include "Maps.h"
#include "MapsNPC.h"
#include "MapsNPCFunctions.h"
#include "MapsFunctions.h"
//���������
#include "ViewsAndWindow.h"
#include "ClassHeroHealthBar.h"
#include "ClassHeroStaminaBar.h"

using namespace sf;


//���H ������� ������ �������� �� ������ �� �����
//����� �� ��������������� ���������� � main ��������� ����������� �� #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
/*void ConsoleCheck(Hero MainHero, float time, bool timecheck, bool speedXH, bool speedHY, bool cooldownJump, bool cooldownSlide, bool comboTimer)		
{
	if (timecheck == true) std::cout << time << "|";												//����� �������
	if (speedXH == true)std::cout << MainHero.Get_speedXH() << "|";									//����� �������� �� �
	if (speedHY == true)std::cout << MainHero.Get_speedXY() << "|";									//����� �������� �� Y
	if (cooldownJump == true)std::cout << MainHero.Get_cooldownAnimationJump() << "|";				//����� �������� ������
	if (cooldownSlide == true)std::cout << MainHero.Get_cooldownAnimationSlide() << "|";			//����� �������� ����������
	if (cooldownSlide == true)std::cout << MainHero.Get_cooldownAnimationSlide() << "|";			//����� �������� ����������
	if (comboTimer == true) std::cout << MainHero.Get_comboTimer() << "|";							//����� ������� �� �����
}*/

int main() {

	RenderWindow window(VideoMode(1280, 720), "Test");									//������ ����
	//window.setFramerateLimit(60);														//����������� FPS
	//window.setVerticalSyncEnabled(true);												//����������� FPS=60

	View MainView;																		//������ ������ ����
	Hero MainHero(1100, 500, 200, 100);													//������� �����
	HeroHealthBar healthBar;															//������� ��� ��������
	HeroStaminaBar staminaBar;															//������� ��� ������������
	MainView.reset(FloatRect(0,0,1280,720));											//��������� ������ ���� �� �����

	Clock clock;													//������� ���������� �������, �.�. �������� �� �������(� �� �������������/�������� ����������).	
	
	float time;
	float stime = 0;																		
	

	//SetLayers(v, v[MainHero.Get_currentMap()].size(), MainHero.Get_currentMap());							//������������� �������� �� �����
	while (window.isOpen())											//��������� ���� ���� �������
	{
		time = clock.getElapsedTime().asMicroseconds();				//�������� ��������� ����� � �������������
		clock.restart();											//������������� ����
		time = time / 800;											//�������� ����
		stime += time;												//������ ������
		
		//ConsoleCheck(MainHero,time, false, true,false,false,false,false);//����, ����� �������� �� ������ � ������� !!!��������������,���� �� ������������, �� ��������� �����!!!

		Event event;
		while (window.pollEvent(event))																		//������� �������� ����
		{
			if (event.type == Event::Closed)
				window.close();
		}


		healthBar.updateBar(MainHero.Get_healthH(), MainHero.Get_healthMaxH(),10);							//��������� ��� ��������
		staminaBar.updateBar(MainHero.Get_staminaH(), MainHero.Get_staminaMaxH(), 10);						//��������� ��� ������������
		
		ControlsMainCharacter(MainHero,time,stime);															//���������� ������� ����������

		ViewXYfromClassHero(MainView, MainHero.Get_XHReal(), MainHero.Get_YHReal());						//����������� ������ ���� �� ���������

		NPCLogic(time, vNPC, MainHero.Get_currentMap());													//������ NPC

		IntersectionObjectsAndNPCs(MainHero, vMaps, vNPC);													//����������� � ��������� ��������� ���� ��������, NPC, ���.

		DrawNPC(MainView, time, vNPC, MainHero.Get_currentMap());											//���������� � ��������� NPC
		DrawEnvironment(MainView, time, vMaps, MainHero.Get_currentMap());									//���������� � ��������� ��������
		MainHero.Draw(time);																				//���������� � ��������� ���������
		
		window.setView(MainView);
		window.clear();																						//������� ���� �� ����������� �������
		
		SpritesObjectsAndNPCs(window, MainHero, vMaps, vNPC);												//��������� �� �����
		
		healthBar.drawHealthBar(window);																	//��������� ��� ��������
		staminaBar.drawStaminaBar(window);																	//��������� ��� ������������
		window.display();																					//�����������


	}

	//������� ������ �� ��� vNPC
	for (auto i = 0; i < vNPC.size(); i++) {
		for (auto j = 0; j < vNPC[i].size(); j++) {
			delete vNPC[i][j];
		}
	}

	//������� ������ �� ��� vMaps
	for (auto i = 0; i < vMaps.size(); i++) {
		for (auto j = 0; j < vMaps[i].size(); j++) {
			delete vMaps[i][j];
		}
	}

	return 0;
}




