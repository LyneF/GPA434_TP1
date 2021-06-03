#pragma once
#ifndef _ATEROID_H_
#define _ASTEROID_H_

#include <EzApp>
#include "Body.h"
#include "GameEngine.h"
#include "Asteroid.h"
#include "Polygon.h"

class Asteroid
{
private:
	Body mBody{ };
	

public:
	Asteroid();
	~Asteroid() = default;

	float processTime(float elapsedTime);
	void drawOnScreen(ezapp::Screen &screen, Vect2D mAsteroidPosition,
	float mAsteroidOrientation,float mAsteroidSize);




};

#endif //_ASTEROID_H_