#pragma once
#ifndef _SHUTTLE_H_
#define _SHUTTLE_H_

#include "Body.h"
#include <ezapp>

class Shuttle
{
private:
	Body mBody{ };
	float mLinearThrustPower{ },
		mAngularThrustPower{ },
		mLinearTraveledDistance{ },
		mAngularTraveledDistance{ };

public:
	void control(const Keyboard &keyboard, GameEngine &gameEngine);
	void processTime(float elapsedTime);
	void drawOnScreen(Screen& screen);
	bool isColliding(const Asteroid& asteroid);

};


#endif // _SHUTTLE_H_