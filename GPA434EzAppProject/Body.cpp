#include "Body.h"

//mShape.buildRegular


void Body::reset()
{
	mPhysics.reset();
	mShape = Polygon();
}

void Body::applyLinearAcceleration(Vect2D acceleration)
{
	mPhysics.applyLinearAcceleration(acceleration);
}

void Body::applyLinearAcceleration(float acceleration)
{
	mPhysics.applyLinearAcceleration(acceleration);
}

void Body::applyAngularAcceleration(float acceleration)
{
	mPhysics.applyAngularAcceleration(acceleration);
}

void Body::processTime(float elapsedTime)
{
	mPhysics.processTime(elapsedTime);
}

void Body::drawOnScreen(ezapp::Screen& screen)
{
	mShape.draw(screen, mPhysics.getLinearPosition_X(), mPhysics.getLinearPosition_Y());
}
