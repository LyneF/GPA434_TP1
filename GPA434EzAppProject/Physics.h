#pragma once
#ifndef PHYSICS_H
#define PHYSICS_H

#include "Vect2D.h"
#include <EzApp>

class Physics
{
private:
	Vect2D mLinearPosition{ };
	Vect2D mLinearVelocity{ };
	Vect2D mLinearAcceleration{ };
	float mAngularPosition{ };
	float mAngularVelocity{ };
	float mAngularAcceleration{ };


public:
	Physics();
	void reset();
	void applyLinearAcceleration(Vect2D acceleration);
	void applyLinearAcceleration(float acceleration);
	void applyAngularAcceleration(float acceleration);
	void processTime(float elapsedTime);
};

#endif // !PHYSICS_H