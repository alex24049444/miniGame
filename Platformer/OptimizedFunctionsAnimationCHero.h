#pragma once
//Объявления вспомогательных функций анимации для главного героя

//Функция воспроизведения анимации скольжения,сначала воспроизводится нециклическая анимация, затем циклическая, затем снова не циклическая анимация
void OnlySlideAnimation(float&, float, float&, float, bool&, int&, int, float&, float&, Sprite&, int, int, float, float, float, float, float, float, float, double, double, double, double);


//Функция воспроизведения анимации прыжка, полностью не циклическая анимация
void OnlyJumpsAnimation(float&, float, float&, float, bool&, int&, int, double, float&, float&, Sprite&, int, int, int, int, float, float, float, float, float, float, float, double, double, double, double);