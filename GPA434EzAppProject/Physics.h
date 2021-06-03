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
	float mBouncingCoeff;
	float mFrictionCoeff;


public:
	Physics();
	Physics(float AngularPosition, float AngularVelocity, float AngularAcceleration);
	~Physics() = default;
	void reset();

	//Accesseurs
	Vect2D getLinearPosition() const;
	float getLinearPosition_X();
	float getLinearPosition_Y();
	Vect2D getLinearVelocity() const;
	float getLinearVelocity_X();
	float getLinearVelocity_Y();
	Vect2D getLinearAcceleration() const;
	float getLinearAcceleration_X();
	float getLinearAcceleration_Y();

	float bouncingCoeff() const;
	float frictionCoeff() const;

	//Mutateurs
	void setPosition(Vect2D const& position);
	void setVelocity(Vect2D const& velocity);
	void setAcceleration(Vect2D const& acceleration);
	void applyLinearAcceleration(Vect2D const& acceleration);
	void applyLinearAcceleration(float acceleration);
	void applyAngularAcceleration(float acceleration);
	//void setCoefficients(float friction, float bouncing);

	//void randomize(...);

	// Fonctions utilitaires
	void processTime(float elapsedTime);

	void manageBorder(float left, float top, float right, float bottom);
};

#endif // PHYSICS_H