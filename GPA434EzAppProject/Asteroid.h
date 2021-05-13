#pragma once
#ifndef _ATEROID_H_
#define _ASTEROID_H_

#include <EzApp>
#include "Body.h"

class Asteroid
{
private:
	Body mBody{ };
	

public:
	float processTime(float elapsedTime);
	void drawOnScreen(ezapp::Screen &screen);




};

#endif //_ASTEROID_H_