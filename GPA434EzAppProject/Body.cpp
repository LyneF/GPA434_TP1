#include "Body.h"

#include <algorithm>
#include "Random.h"

//mPolygon.buildRegular

Body::Body(float radius, unsigned outlineColor, unsigned fillColor)
	: mBouncingCount{}
{
	mPolygon.buildCircle(1.0f);
	setRadius(radius);
	setColors(outlineColor, fillColor);
}

bool Body::isToBeRemoved() const
{
	return mBouncingCount >= 2;
}

Polygon& Body::polygon()
{
	return mPolygon;
}

Physics& Body::physics()
{
	return mPhysics;
}

float& Body::radius()
{
	return mRadius;
}

void Body::reset()
{
	//mPolygon=Polygon();
	mPhysics.reset();
	mRadius = 1.0f;
}

void Body::setBody(Physics const& body)
{
	mPhysics = body;
}

void Body::setRadius(float radius)
{
	mRadius = std::clamp(radius, 0.5f, 1000.0f);
	mPolygon.outlineWidth() = 1.0 / mRadius;
	mPolygon.setOutlineWidth();
}

void Body::setColors(unsigned outlineColor, unsigned fillColor)
{
	mPolygon.setBrushColor(fillColor);
	mPolygon.setPenColor(outlineColor);
}

void Body::applyLinearAcceleration(Vect2D const& acceleration)
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
	mPolygon.draw(screen, mPhysics.getLinearPosition_X(), mPhysics.getLinearPosition_Y());
}

void Body::randomize(float left, float top, float right, float bottom, float maxSpeed, float minRadius, float maxRadius)
{
	// TO DO : Validate inputs!!!

	mPhysics.setPosition(Vect2D::randomized(left, right, top, bottom));
	mPhysics.setVelocity(Vect2D::randomized(-maxSpeed, maxSpeed));
	setRadius(Random::real(minRadius, maxRadius));
	mPolygon.shapeColors().getFillColor().randomize();
	//mPhysics.setCoefficients(Random::real(0.75f, 1.0f), Random::real(0.75f, 1.0f));
}

/*
void Body::bounceBorder(float left, float top, float right, float bottom)
{
	if (mPhysics.getLinearPosition().x() < left + mRadius) {
		float newXPos{ left + 2.0f * mRadius + (left - mPhysics.getLinearPosition().x()) };
		mPhysics.setPosition(Vect2D(newXPos, mPhysics.getLinearPosition().y()));
		mPhysics.setVelocity(Vect2D(-mPhysics.getLinearVelocity().x() * mPhysics.bouncingCoeff(),
			mPhysics.getLinearVelocity().y() * mPhysics.frictionCoeff()));
		++mBouncingCount;
	}
	else if (mPhysics.getLinearPosition().x() > right - mRadius) {
		float newXPos{ right - 2.0f * mRadius - (mPhysics.getLinearPosition().x() - right) };
		mPhysics.setPosition(Vect2D(newXPos, mPhysics.getLinearPosition().y()));
		mPhysics.setVelocity(Vect2D(-mPhysics.getLinearVelocity().x() * mPhysics.bouncingCoeff(),
			mPhysics.getLinearVelocity().y() * mPhysics.frictionCoeff()));
		++mBouncingCount;
	}
	if (mPhysics.getLinearPosition().y() < top + mRadius) {
		float newYPos{ top + 2.0f * mRadius + (left - mPhysics.getLinearPosition().y()) };
		mPhysics.setPosition(Vect2D(mPhysics.getLinearPosition().x(), newYPos));
		mPhysics.setVelocity(Vect2D(mPhysics.getLinearVelocity().x() * mPhysics.frictionCoeff(),
			-mPhysics.getLinearVelocity().y() * mPhysics.bouncingCoeff()));
		++mBouncingCount;
	}
	else if (mPhysics.getLinearPosition().y() > bottom - mRadius) {
		float newYPos{ bottom - 2.0f * mRadius - (mPhysics.getLinearPosition().y() - bottom) };
		mPhysics.setPosition(Vect2D(mPhysics.getLinearPosition().x(), newYPos));
		mPhysics.setVelocity(Vect2D(mPhysics.getLinearVelocity().x() * mPhysics.frictionCoeff(),
			-mPhysics.getLinearVelocity().y() * mPhysics.bouncingCoeff()));
		++mBouncingCount;
	}
}
*/

