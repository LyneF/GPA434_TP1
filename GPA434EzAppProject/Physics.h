#pragma once
#ifndef PHYSICS_H
#define PHYSICS_H

#include <EzApp>
#include "Vect2D.h"

class Physics
{
private:
	Vect2D mLinearPosition;
	Vect2D mLinearVelocity;
	Vect2D mLinearAcceleration;
	float mAngularPosition;
	float mAngularVelocity;
	float mAngularAcceleration;


public:
	Physics();
	Physics(float AngularPosition, float AngularVelocity, float AngularAcceleration);
	~Physics();
	void reset();

	Vect2D getLinearPosition();
	float getLinearPosition_X();
	float getLinearPosition_Y();
	Vect2D getLinearVelocity();
	float getLinearVelocity_X();
	float getLinearVelocity_Y();
	Vect2D getLinearAcceleration();
	float getLinearAcceleration_X();
	float getLinearAcceleration_Y();

	void applyLinearAcceleration(Vect2D acceleration);
	void applyLinearAcceleration(float acceleration);
	void applyAngularAcceleration(float acceleration);
	void processTime(float elapsedTime);
};

#endif // PHYSICS_H