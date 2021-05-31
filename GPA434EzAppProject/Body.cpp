#include "Body.h"

//mShape.buildRegular

Body::Body()
{
	reset();
}

void Body::reset()
{
	mBody.reset();
	mShape = Polygon();
}

void Body::applyLinearAcceleration(Vect2D acceleration)
{
	mBody.applyLinearAcceleration(acceleration);
}

void Body::applyLinearAcceleration(float acceleration)
{
	mBody.applyLinearAcceleration(acceleration);
}

void Body::applyAngularAcceleration(float acceleration)
{
	mBody.applyAngularAcceleration(acceleration);
}

void Body::processTime(float elapsedTime)
{
	mBody.processTime(elapsedTime);
}

void Body::drawOnScreen(ezapp::Screen& screen)
{
	mShape.draw(screen, mBody.getLinearPosition_X(), mBody.getLinearPosition_Y());
}
