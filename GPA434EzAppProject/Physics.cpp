#include "Physics.h"

Physics::Physics()
{
}

void Physics::reset()
{
	mLinearPosition.set(0.0f, 0.0f);
	mLinearVelocity.set(0.0f, 0.0f);
	mLinearAcceleration.set(0.0f, 0.0f);
	mAngularAcceleration = 0.0f;
	mAngularPosition = 0.0f;
	mAngularVelocity = 0.0f;
}
//Additionne une acc�l�ration � celle d�j� existante
void Physics::applyLinearAcceleration(Vect2D acceleration)
{
	mLinearAcceleration.x += acceleration.x;
	mLinearAcceleration.y += acceleration.y;
}

void Physics::applyLinearAcceleration(float acceleration)
{
	
}
//Mise � jour des positions et vitesses selon Newton
void Physics::processTime(float elapsedTime)
{
	//formules de Newton
}
