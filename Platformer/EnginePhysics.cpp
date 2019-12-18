//��� ������������� ����������� ����������� ������

/*
������� Physics : ������, �������� �� ���������� ������ � ����
speedX - ��������� �� ��� �
speedY - ��������� �� ��� Y
clutchObj - ���������� ��������� � ��������, ��� �� ������, ��� ������� "�������" ���������, ������ - �������� ��������
msX(movementspeedX = ms) - �������� �� �, � �������� ��������� speedX
msY - �������� �� Y, � �������� ��������� speedY
clutchX / clutchY - ���������� ��������� ��������
addX / addY - ��� ���������(��� �������, ������, ���), ���� �� ����� : ������ 0.
*/

void Physics(float& speedX, float& speedY, float time, float clutchObj, float msX, float msY, float clutchX, float clutchY, float addX, float addY) {
	speedX += addX * time;
	speedY += addY * time;

	if (speedX < (msX + 0.001 * time * clutchX * clutchObj) && speedX >(msX - 0.001 * time * clutchX * clutchObj)) speedX = msX;
	else {
		if (speedX > msX)speedX -= 0.001 * clutchX * clutchObj * time;
		if (speedX < msX)speedX += 0.001 * clutchX * clutchObj * time;
	}
	if (speedY < (msY + 0.001 * time * clutchY * clutchObj) && speedY >(msY - 0.001 * time * clutchY * clutchObj)) speedY = msY;
	else {
		if (speedY > msY)speedY -= 0.001 * clutchY * clutchObj * time;
		if (speedY < msY)speedY += 0.001 * clutchY * clutchObj * time;
	}
}