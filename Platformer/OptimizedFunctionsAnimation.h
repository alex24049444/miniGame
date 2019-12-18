#pragma once
//Объявления вспомогательных функций анимации для любых объектов/персонажей


//Функция CycleAnimation: воспроизведение ЦИКЛИЧЕСКОЙ анимации, именно она отвечает за двигающуюся картинку.
void CycleAnimation(float&, float, double, int, Sprite&, int, int, int, int, int);


//Функция UncycleAnimation : воспроизведение НЕЦИКЛИЧЕСКОЙ анимации.
void UncycleAnimation(float&, float, bool&, int&, int, double, Sprite&, int, int, int, int);
//функция uncycleAnimation : без хуйни
void UncycleAnimationMob(float&, float, bool&, double, Sprite&, int, int, int, int, int);