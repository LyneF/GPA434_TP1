#include "Body.h"

#include <algorithm>
#include "Random.h"

//mShape.buildRegular

Body::Body(float radius, Color const& outlineColor, Color const& fillColor)
	: mBouncingCount{}
{
	mShape.buildCircle(1.0f);
	setRadius(radius);
	setColors(outlineColor, fillColor);
}

bool Body::isToBeRemoved() const
{
	return mBouncingCount >= 2;
}

Polygon Body::shape() const
{
	return mShape;
}

Physics Body::body() const
{
	return mBody;
}

float Body::radius() const
{
	return mRadius;
}

void Body::reset()
{
	mBody.reset();
	mShape = Polygon();
}

void Body::setBody(Physics const& body)
{
	mBody = body;
}

void Body::setRadius(float radius)
{
	mRadius = std::clamp(radius, 0.5f, 1000.0f);
	mShape.setOutlineWidth(1.0f / mRadius);
}

void Body::setColors(Color const& outlineColor, Color const& fillColor)
{
	mShape.fillColor() = fillColor;
	mShape.outlineColor() = outlineColor;
}

void Body::applyLinearAcceleration(Vect2D const& acceleration)
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

void Body::drawOnScreen(ezapp::Screen& screen) const
{
	mShape.draw(screen, mBody.getLinearPosition_X(), mBody.getLinearPosition_Y());
}

void Body::randomize(float left, float top, float right, float bottom, float maxSpeed, float minRadius, float maxRadius)
{
	// TO DO : Validate inputs!!!

	mBody.setPosition(Vect2D::randomized(left, right, top, bottom));
	mBody.setVelocity(Vect2D::randomized(-maxSpeed, maxSpeed));
	setRadius(Random::real(minRadius, maxRadius));
	mShape.fillColor().randomize();
	mBody.setCoefficients(Random::real(0.75f, 1.0f), Random::real(0.75f, 1.0f));
}

void Body::bounceBorder(float left, float top, float right, float bottom)
{
	if (mBody.getLinearPosition().x() < left + mRadius) {
		float newXPos{ left + 2.0f * mRadius + (left - mBody.getLinearPosition().x()) };
		mBody.setPosition(Vect2D(newXPos, mBody.getLinearPosition().y()));
		mBody.setVelocity(Vect2D(-mBody.getLinearVelocity().x() * mBody.bouncingCoeff(),
			mBody.getLinearVelocity().y() * mBody.frictionCoeff()));
		++mBouncingCount;
	}
	else if (mBody.getLinearPosition().x() > right - mRadius) {
		float newXPos{ right - 2.0f * mRadius - (mBody.getLinearPosition().x() - right) };
		mBody.setPosition(Vect2D(newXPos, mBody.getLinearPosition().y()));
		mBody.setVelocity(Vect2D(-mBody.getLinearVelocity().x() * mBody.bouncingCoeff(),
			mBody.getLinearVelocity().y() * mBody.frictionCoeff()));
		++mBouncingCount;
	}
	if (mBody.getLinearPosition().y() < top + mRadius) {
		float newYPos{ top + 2.0f * mRadius + (left - mBody.getLinearPosition().y()) };
		mBody.setPosition(Vect2D(mBody.getLinearPosition().x(), newYPos));
		mBody.setVelocity(Vect2D(mBody.getLinearVelocity().x() * mBody.frictionCoeff(),
			-mBody.getLinearVelocity().y() * mBody.bouncingCoeff()));
		++mBouncingCount;
	}
	else if (mBody.getLinearPosition().y() > bottom - mRadius) {
		float newYPos{ bottom - 2.0f * mRadius - (mBody.getLinearPosition().y() - bottom) };
		mBody.setPosition(Vect2D(mBody.getLinearPosition().x(), newYPos));
		mBody.setVelocity(Vect2D(mBody.getLinearVelocity().x() * mBody.frictionCoeff(),
			-mBody.getLinearVelocity().y() * mBody.bouncingCoeff()));
		++mBouncingCount;
	}
}


