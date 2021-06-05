#pragma once
#ifndef _MISSILE_H
#define _MISSILE_H

// Inclusion des biblioth�ques
#include <ezapp>
#include "Body.h"
#include "Asteroid.h"

//Classe permettant de 
class Missile
{
private:
	Body mBody{ };
	float mFuelLevel{ },
		  mThrustPower{ };	


public:
	float processTime(float elapsedTime);
	void drawOnScreen(ezapp::Screen& screen);
	bool isColliding(const Asteroid& asteroid);





};

#endif //_MISSILE_H_