//Тут располагается определение физического движка

/*
Функция Physics : физика, отвечает за правильную физику в игре
speedX - ускорение по оси Х
speedY - ускорение по оси Y
clutchObj - показатель сцепления с объектом, чем он меньше, тем сильнее "заносит" персонажа, больше - обратная ситуация
msX(movementspeedX = ms) - значение по Х, к которому стремится speedX
msY - значение по Y, к которому стремится speedY
clutchX / clutchY - показатель сцепления анимации
addX / addY - доп ускорение(для прыжков, рывков, итд), если не нужно : ставим 0.
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