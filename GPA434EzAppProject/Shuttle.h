#pragma once
#ifndef _SHUTTLE_H_
#define _SHUTTLE_H_

#include <ezapp>
#include "Body.h"
#include "GameEngine.h"
#include "Asteroid.h"
#include "Polygon.h"


class Shuttle
{
private:
	Body mBody{ };
	float mLinearThrustPower{ },
		mAngularThrustPower{ },
		mLinearTraveledDistance{ },
		mAngularTraveledDistance{ };
	Vect2D mShuttlePosition;
	float mShuttleOrientation;
	float mShuttleSize;
	
public:
	Shuttle();
	~Shuttle() = default;


	void control(const ezapp::Keyboard &keyboard, GameEngine &gameEngine);
	void processTime(float elapsedTime);
	void drawOnScreen(ezapp::Screen& screen, Vect2D mShuttlePosition, 
	float mShuttleOrientation, float mShuttleSize);
	bool isColliding(const Asteroid& asteroid);

	
};


#endif // _SHUTTLE_H_

