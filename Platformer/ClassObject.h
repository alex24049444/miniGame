#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

//����� ��������
//TODO: ��������� ��� ��������������
class Object
{
protected:
	float xR;							//��������� ������ �� ����� �� �
	float yR;							//��������� ������ �� ����� �� Y
	float xM;							//����� X ������ �������� � �����
	float yM;							//����� Y ������ �������� � �����
	float wM;							//������ ��������
	float hM;							//������ ��������
	float xRReal;						//��������� ���������� ������ �� ����� �� �
	float yRReal;						//��������� ���������� ������ �� ����� �� Y
	float xRRealInside;					//X �������� ������ ������ ����������� ������
	float yRRealInside;					//Y �������� ������ ������ ����������� ������
	float wRReal;						//������ ���������� ������
	float hRReal;						//������ ���������� ������
	float clutch;						//���������	1-���������� <1-���������� >1-����������
	float trackingCoefficient;			//����������� �������� ������� >1
	signed int layer = 0;				//���� �� ������� �������������� ������
	signed int layerSub = 0;			//���������� ����, ��� ������� ��������.

	bool passable;						//�������� �� ������ ��� ����������� ������ ���� ������
	bool passableJump;					//�������� �� ������ ��� ����������� ������ ���� �������
	bool passableSlide;					//�������� �� ������ ��� ����������� ������ ���� �����������
	bool passableCrouch;				//�������� �� ������ ��� ����������� ������ ���� ��������
	bool crossable;						//������ �� ����� ��������� ���������� ���� ������?
	bool tracking;						//�������� ������
	bool visible;						//��������� �������
	bool animated;						//���������� ������ ��� �������� ��������� � ������������? ��� �����������.
	bool movableO;						//�������� �� ������ ������� ����������� ���� ������?
	//bool rendered = false;				//��������� �� ������?

	//String filePath;
	Image imageObject;
	Texture textureObject;
	Sprite spriteObject;

public:
	Object() {};		//����������� �� ���������

	virtual void Draw(View);						//��������� ������� � ������� �� ������������ ����� ��� ���������

	virtual int Animation(float) { return 0; };		//�������� ��� ClassObjectAnim

	void DetermineLayer();							//��������� ����

	//��������������� Get-�������

	Sprite Get_Sprite() { return spriteObject; }	//��������� �������
	float Get_xR() { return xR; }					//���������	������ �� ����� �� �
	float Get_yR() { return yR; }					//���������	������ �� ����� �� Y
	float Get_xM() { return xM; }					//��������� X ������ ��������
	float Get_yM() { return yM; }					//��������� Y ������ ��������
	float Get_wM() { return wM; }					//��������� ������ ��������
	float Get_hM() { return hM; }					//��������� ������ ��������
	float Get_xRReal() { return xRReal; }			//��������� X ������ ���������� ������
	float Get_yRReal() { return yRReal; }			//��������� Y ������ ���������� ������
	float Get_wRReal() { return wRReal; }			//��������� ������ ���������� ������
	float Get_hRReal() { return hRReal; }			//��������� ������ ���������� ������
	float Get_clutch() { return clutch; }			//��������� ���������
	float Get_trackingCoefficient() { return trackingCoefficient; }			//��������� ���������
	signed int Get_layer() { return layer; }								//��������� ���� �� ������� ������������� ������
	bool Get_passable() { return passable; }				//��������� ����������� ����������� ������ ������
	bool Get_passableJump() { return passableJump; }		//��������� ����������� ����������� ������ ������ �������
	bool Get_passableSlide() { return passableSlide; }		//��������� ����������� ����������� ������ ������ �����������
	bool Get_passableCrouch() { return passableCrouch; }	//��������� ����������� ����������� ������ ������ ��������
	bool Get_crossable() { return crossable; }				//�� ����� ������������ � ������ ��������?
	//bool Get_rendered() { return rendered; }				//����c���� ��� ������?
	bool Get_tracking() { return tracking; }				//�������� �� ������?
	bool Get_animated() { return animated; }				//������������� �� ������?
	bool Get_movableO() { return movableO; }				//������ �� ������?

	//��������������� Set-�������

	void Set_layer(signed int value) { layer = value; }		//��������� ����
	void Set_crossable(bool value) { crossable = value; }	//��������� ����������� �����������
	void Set_xRReal(float value) { xRReal = value; }		//���������� x ��a����� ������
	void Set_yRReal(float value) { yRReal = value; }		//���������� y ��a����� ������
	void Set_spritePosition(float x, float y) { spriteObject.setPosition(x, y); }	//���������� ��������� �������, ���������� �� ���� ��������� � draw
	//void Set_rendered(bool value) { rendered = value; }		//��������� �������
};