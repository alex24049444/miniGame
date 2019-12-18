#pragma once
/*
Тут описываем Героя, Его положение по х/y, анимации итд
Только объявление! Исключение: Функции-Помощники
*/

#include <SFML/Graphics.hpp>

using namespace sf;

//TODO: Разрешить все предупреждения
class Hero
{
private:
	float xH;							//Положение виртуальной модели по х
	float yH;							//Положение виртуальной модели по y
	float wH;							//Ширина модели
	float hH;							//Высота модели
	float dxH;							//Ускорение по х
	float dyH;							//Ускорение по у
	float xHReal;						//Х реальной модели внутри виртуальной модели относительной всей оси
	float yHReal;						//Y реальной модели внутри виртуальной модели относительной всей оси
	float xHRealInside;					//Х реальной модели внутри виртуальной модели
	float yHRealInside;					//Y реальной модели внутри виртуальной модели
	float wHRealInside;					//Ширина реальной модели внутри виртуальной модели
	float hHRealInside;					//Высота реальной модели внутри виртуальной модели
	float speedHX=0;					//Скорость персонажа по x
	float speedHY=0;					//Скорость персонажа по y
	float clutchObj = 1;				//Сцепление персонажа с поверхностью на которой он стоит
	int dirH;							//Направление движения	Данная "роза направлений" будет использоваться часто,советую её запомнить.

											//7 4 8
											// ↖↑↗
											//3←0→1
											// ↙↓↘
											//6 2 5
	Image image;						//Изображение
	Texture texture;					//Текстура
	Sprite sprite;						//Спрайт
	signed int layerH;					//Слой отрисовки

	int currentMap = 0;					//Текущая карта

	bool battleMode = false;			//Боевая стойка
	bool battleModeAvaible = false;		//Проверка на боевую стойку
	bool moveLeft = true;				//Нужна для проверки на стандартное движение влево
	bool moveOnlyLeft = true;			//Проверка на лево и прямо
	bool moveRight = true;				//Нужна для проверки на стандартное движение вправо
	bool moveOnlyRight = true;			//Проверка на право и прямо
	bool buttonIsPressed = false;		//Нажата ли клавиша нужно для idle
	bool previousDirectionMove = false; //Предыдущее направление движения false-вправо true-влево
	bool crouchCheck = true;			//Можно ли присесть,исключает возможность воспроизведения анимации HeroCrouchIdle в движении
	bool crouchAviable = false;			//Приседаем?
	bool slideAviable = false;			//Скользим?
	bool jumpAviable = false;			//Прыгаем?
	bool jumpLargeAviable = false;		//Далеко прыгаем?
	bool controlAviable = true;			//Контроль управления с клавиатуры
	bool onlyOneAnimation = true;		//Воспроизведение только одной анимации по всем направлениям
	bool onlyOneAnimationOneDir = true;	//Воспроизведение только одной анимации в одном направлении
	bool hitAviableLight = false;		//Наносим легкий удар?
	bool hitAviableHeavy = false;		//Наносим тяжелый удар?

	float currentFrame = 0;				//Номер текущего кадра циклической анимации
	float currentUncycleFrame = 0;		//Номер текущего кадра не циклической анимации

	float cooldownAnimationJump = 0;	//Кулдаун на анимацию прыжков
	float cooldownAnimationSlide = 0;	//Кулдаун на анимацию скольжения
	float comboTimer = 0;				//Время до следующего удара в комбо

	int staminaH;						//Выносливость героя
	int staminaMaxH;					//Максимальная выносливость героя
	int healthH;						//Здоровье героя
	int healthMaxH;						//Максимальное здоровье героя
	int comboH = 0;						//Текущее комбо
	int comboHitH = 0;					//Текущий удар в комбо
	//FloatRect rectH;

public:
	FloatRect rectH;
	Hero(float X, float Y, int Health, int Stamina)			//Конструктор 
	{
		image.loadFromFile("Sprites/HeroSpritesBig.png");	//Загружаем в него файл
		image.createMaskFromColor(Color(255, 255, 255));	//Прозрачность
		texture.loadFromImage(image);						//Текстура
		sprite.setTexture(texture);							//Спрайт
		xH = X;												//Координаты
		yH = Y;
		wH = 100;
		hH = 74;
		xHRealInside = 46;
		yHRealInside = 57;
		wHRealInside = 15;
		hHRealInside = 15;
		/*xHRealInside = 30;
		yHRealInside = 15;
		wHRealInside = 45;
		hHRealInside = 59;*/
		xHReal = xH + xHRealInside;
		yHReal = yH + yHRealInside;
		FloatRect d(xHReal, yHReal, 10, 10);
		rectH = d;
		healthH = Health;									//Здоровье текущее
		healthMaxH = Health;								//Здоровье максимальное
		staminaH = Stamina;									//Выносливость текущая
		staminaMaxH = Stamina;								//Выносливость максимальная
		sprite.setTextureRect(IntRect(0, 0, wH, hH));		//Вырезаем персонажа
	}
	//Функции-CHANGE помощники, могут изменять значения
	void Change_speedHX(float value) { speedHX += value; }
	void Change_speedHY(float value) { speedHY += value; }
	void Change_cooldownAnimationJump(float value) { cooldownAnimationJump += value; }
	void Change_cooldownAnimationSlide(float value) { cooldownAnimationSlide += value; }
	void Change_comboTimer(float value) { comboTimer += value; }
	void Change_comboHitH(float value) { comboHitH += value; }

	FloatRect getRect() { return rectH; }; // получить прямоугольник
	//Функции-GET помощники
	Sprite Get_Sprite() { return sprite; }										//Получить Спрайт
	int Get_currentMap() { return currentMap; }									//Узнать на какой карте сейчас находимся
	int Get_healthH() { return healthH; }										//Узнать значение здоровья персонажа
	int Get_healthMaxH() { return healthMaxH; }									//Узнать максимальное здоровье персонажа
	int Get_staminaH() { return staminaH; }										//Узнать значение выносливости персонажа
	int Get_staminaMaxH() { return staminaMaxH; }								//Узнать максимальную выносливость персонажа
	signed int Get_layerH() { return layerH; }									//Получение слоя на котором располагается персонаж
	float Get_XH() { return xH; }												//Получить положение виртуальной модели по х
	float Get_YH() { return yH; }												//Получить положение виртуальной модели по у
	float Get_WH() { return wH; }												//Получить ширину модели
	float Get_HH() { return hH; }												//Получить высоту модели
	float Get_XHReal() { return xHReal; }										//Получить положение реальной модели по х
	float Get_YHReal() { return yHReal; }										//Получить положение реальной модели по у
	float Get_XHRealInside() { return xHRealInside; }							//Получить отступ по х внутри физической модели
	float Get_YHRealInside() { return yHRealInside; }							//Получить отступ по y внутри физической модели
	float Get_WHRealInside() { return wHRealInside; }							//Получить ширину физической модели
	float Get_HHRealInside() { return hHRealInside; }							//Получить высоту физической модели
	float Get_speedXH() { return speedHX; }										//Получить speedHX
	float Get_speedXY() { return speedHY; }										//Получить speedHY
	float Get_clutchObj() { return clutchObj; }									//Получить величину сцепления персонажа с поверхностью на которой он стоит
	float Get_cooldownAnimationJump() { return cooldownAnimationJump; }			//Получить cooldownAnimationJump
	float Get_cooldownAnimationSlide() { return cooldownAnimationSlide; }		//Получить cooldownAnimationSlide
	float Get_comboTimer() { return comboTimer; }								//Получить comboTimer
	float Get_comboHitH() { return comboHitH; }									//Получить comboHitH
	float Get_comboH() { return comboH; }										//Получить comboH
	bool Get_moveLeft() { return moveLeft; }									//Можно ли двигаться влево
	bool Get_moveOnlyLeft() { return moveOnlyLeft; }							//Можно ли двигаться только прямо влево
	bool Get_moveRight() { return moveRight; }									//Можно ли двигаться вправо
	bool Get_moveOnlyRight() { return moveOnlyRight; }							//Можно ли двигаться только прямо вправо
	bool Get_buttonIsPressed() { return buttonIsPressed; }						//Нажата ли кнопка
	bool Get_previousDirectionMove() { return previousDirectionMove; }			//Узнать предыдущее направление false-вправо true-влево
	bool Get_crouchCheck() { return crouchCheck; }								//Можно ли присесть true-да, false-нет
	bool Get_crouchAviable() { return crouchAviable; }							//Доступен ли присед
	bool Get_slideAviable() { return slideAviable; }							//Доступно ли скольжение
	bool Get_jumpAviable() { return jumpAviable; }								//Доступен ли прыжок
	bool Get_jumpLargeAviable() { return jumpLargeAviable; }					//Доступен ли мощный прыжок
	bool Get_controlAviable() { return controlAviable; }						//Доступно ли управление с клавиатуры
	bool Get_onlyOneAnimation() { return onlyOneAnimation; }					//Возможно ли воспроизведение только одной анимации
	bool Get_onlyOneAnimationOneDir() { return onlyOneAnimationOneDir; }		//Возможно ли воспроизведение только одной анимации в одном направлении
	bool Get_battleMode() { return battleMode; }								//Какая стойка
	bool Get_battleModeAvaible() { return battleModeAvaible; }					//Возможно ли переключение в другую стойку
	bool Get_hitAviableLight() { return hitAviableLight; }						//Наносим ли легкий удар
	bool Get_hitAviableHeavy() { return hitAviableHeavy; }						//Наносим ли тяжелый удар

	//Функции-SET помощники
	void Set_currentMap(int value) { currentMap = value; }						//Установить номер текущей карты
	void Set_healthH(int value) { healthH = value; }							//Установить текущее здоровье героя
	void Set_healthMaxH(int value) { healthMaxH = value; }						//Установить максимальное здоровье героя
	void Set_staminaH(int value) { staminaH = value; }							//Установить текущую выносливость героя
	void Set_staminaMaxH(int value) { staminaMaxH = value; }					//Установить максимальную выносливость героя
	void Set_XH(float value) { xH = value; }									//Установить положение виртуальной модели по х
	void Set_YH(float value) { yH = value; }									//Установить положение виртуальной модели по у
	void Set_XHReal(float value) { xHReal = value; }							//Установить положение реальной модели по х
	void Set_YHReal(float value) { yHReal = value; }							//Установить положение реальной модели по у
	void Set_layerH(signed int value) { layerH = value; }						//Установка слоя
	void Set_WHRealInside(float value) { wHRealInside = value; }				//Установить ширину физической модели
	void Set_HHRealInside(float value) { hHRealInside = value; }				//Установить высоту физической модели
	void Set_clutchObj(float value) { clutchObj = value; }						//Установить величину сцепления персонажа с поверхностью на которой он стоит
	void Set_moveLeft(bool value) { moveLeft=value; }							//Установить движение влево
	void Set_moveOnlyLeft(bool value) { moveOnlyLeft=value; }					//Установить движение только прямо влево
	void Set_moveRight(bool value) { moveRight=value; }							//Установить движение вправо
	void Set_moveOnlyRight(bool value) { moveOnlyRight=value; }					//Установить движение только прямо вправо
	void Set_buttonIsPressed(bool value) { buttonIsPressed=value; }				//Установить нажатие клавиши
	void Set_previousDirectionMove(bool value) { previousDirectionMove=value; }	//Установить предыдущее направление движения
	void Set_crouchCheck(bool value) { crouchCheck=value; }						//Установить присед
	void Set_crouchAviable(bool value) { crouchAviable = value; }				//Установить возможность приседать
	void Set_slideAviable(bool value) { slideAviable=value; }					//Установить возможность скользить
	void Set_jumpAviable(bool value) { jumpAviable=value; }						//Установить возможность прыжка
	void Set_jumpLargeAviable(bool value) { jumpLargeAviable=value; }			//Установить возможность мощного прыжка
	void Set_controlAviable(bool value) { controlAviable=value; }				//Установить возможность управления персонажем с клавиатуры
	void Set_onlyOneAnimation(bool value) { onlyOneAnimation = value; }			//Установить воспроизведение только одной анимации
	void Set_onlyOneAnimationOneDir(bool value){onlyOneAnimationOneDir = value;}//Установить воспроизведение только одной анимации в одном направлении
	void Set_battleMode(bool value) { battleMode = value; }						//Установить стойку
	void Set_battleModeAvaible(bool value) { battleModeAvaible = value; }		//Установить возможность смены стойки
	void Set_hitAviableLight(bool value) { hitAviableLight = value; }			//Установить нанесение легкого удара
	void Set_hitAviableHeavy(bool value) { hitAviableHeavy = value; }			//Установить нанесение тяжелого удара
	void Set_comboH(float value) { comboH = value; }							//Установить текущее комбо
	void Set_comboHitH(float value) { comboHitH = value; }						//Установить текущий удар в комбо


	void Draw(float);															//Отрисовка персонажа, связь физики и анимации
	void SetRealSize(float, float, float, float);								//Изменение размеров внутренней модели

	/*
	Функции отвечающие за связь анимации и её физической составляющей
	*/
	//Движение вверх-вниз 
	int HeroMoveTop(float,bool,bool,bool);
	int HeroMoveDown(float,bool,bool,bool);

	//AFK	
	int HeroIdleLeft(float);
	int HeroIdleRight(float);
	int HeroIdleCrouchLeft(float);
	int HeroIdleCrouchRight(float);

	//Скольжение	
	void HeroSlideChoise(float);
	int HeroSlideRight(float);
	int HeroSlideRightUp(float);
	int HeroSlideRightDown(float);
	int HeroSlideLeft(float);
	int HeroSlideLeftUp(float);
	int HeroSlideLeftDown(float);

	//Выбор прыжка
	void HeroJumpChoise(float);
	void HeroJumpLargeChoise(float);

	//Малые прыжки	
	int HeroJumpRight(float);
	int HeroJumpRightUp(float);
	int HeroJumpRightDown(float);
	int HeroJumpLeft(float);
	int HeroJumpLeftUp(float);
	int HeroJumpLeftDown(float);

	//Большие прыжки	
	int HeroJumpLargeRight(float);	
	int HeroJumpLargeRightUp(float);
	int HeroJumpLargeRightDown(float);
	int HeroJumpLargeLeft(float);
	int HeroJumpLargeLeftUp(float);
	int HeroJumpLargeLeftDown(float);

	//Движение вправо	
	int HeroMoveRight(float);
	int HeroMoveRightFast(float);
	int HeroMoveRightSlow(float);
	int HeroMoveRightCrouch(float);
	int HeroMoveRightUp(float);
	int HeroMoveRightFastUp(float);
	int HeroMoveRightSlowUp(float);
	int HeroMoveRightCrouchUp(float);
	int HeroMoveRightDown(float);
	int HeroMoveRightFastDown(float);
	int HeroMoveRightSlowDown(float);
	int HeroMoveRightCrouchDown(float);

	//Движение влево	
	int HeroMoveLeft(float);
	int HeroMoveLeftFast(float);
	int HeroMoveLeftSlow(float);
	int HeroMoveLeftCrouch(float);
	int HeroMoveLeftUp(float);
	int HeroMoveLeftFastUp(float);
	int HeroMoveLeftSlowUp(float);
	int HeroMoveLeftCrouchUp(float);
	int HeroMoveLeftDown(float);
	int HeroMoveLeftFastDown(float);
	int HeroMoveLeftSlowDown(float);
	int HeroMoveLeftCrouchDown(float);
	
	//Боевка
	int HeroChangeModToBattleLeft(float);
	int HeroChangeModToCivilLeft(float);
	int HeroChangeModToBattleRight(float);
	int HeroChangeModToCivilRight(float);
	int LightBlowRight(float);
	int HeavyBlowRight(float);
	int LightBlowLeft(float);
	int HeavyBlowLeft(float);


	//Через эту функцию происходит получение урона героем
	void HeroGetDamage();
	
	//Диалоги героя
	void HeroDialogs();


	//~Hero() {}; Деструктор пока в комментах ибо нефиг
};


inline void Hero::HeroDialogs()
{
}