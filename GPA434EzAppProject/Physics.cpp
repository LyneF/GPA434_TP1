#include "Physics.h"

//Constructeur
Physics::Physics()
	: mAngularPosition{ },
	mAngularVelocity{ },
	mAngularAcceleration{ },
	mLinearPosition(),
	mLinearVelocity(),
	mLinearAcceleration()
{
}

Physics::Physics(float AngularPosition, float AngularVelocity, float AngularAcceleration)
{
	mAngularPosition = AngularPosition;
	mAngularVelocity = AngularVelocity;
	mAngularAcceleration = AngularAcceleration;
}

//Destructeur
Physics:: ~Physics() // ne fait rien
{
}

//Réinitialisation des paramètres
void Physics::reset()
{
	//Remise à zéro pour que les accélérations ne soient pas trop grosses
	mAngularAcceleration = 0.0f;
	mLinearAcceleration.reset();
}

Vect2D Physics::getLinearPosition()
{
	return mLinearPosition;
}
float Physics::getLinearPosition_X()
{
	return mLinearPosition.x();
}
float Physics::getLinearPosition_Y()
{
	return mLinearPosition.y();
}
Vect2D Physics::getLinearVelocity()
{
	return mLinearVelocity;
}
float Physics::getLinearVelocity_X()
{
	return mLinearVelocity.x();
}
float Physics::getLinearVelocity_Y()
{
	return mLinearVelocity.y();
}
Vect2D Physics::getLinearAcceleration()
{
	return mLinearAcceleration;
}
float Physics::getLinearAcceleration_X()
{
	return mLinearAcceleration.x();
}
float Physics::getLinearAcceleration_Y()
{
	return mLinearAcceleration.y();
}

//Utiliser des opérateurs dans Vect2D
//Additionne une accélération linéaire à celle déjà existante
void Physics::applyLinearAcceleration(Vect2D acceleration)
{
	//composé des float linear et angular?????
	mLinearAcceleration += acceleration;
}

//Additionne une accélération linéaire à celle déjà existante

void Physics::applyLinearAcceleration(float acceleration)
{
	mLinearAcceleration += acceleration;
}

//Additionne une accélération angulaire à celle déjà existante
void Physics::applyAngularAcceleration(float acceleration)
{
	mAngularAcceleration += acceleration;
}


//Mise à jour des positions et vitesses selon Newton
void Physics::processTime(float elapsedTime)
{	
	//Formules de Newton
	//position linéaire
	mLinearPosition += mLinearVelocity * elapsedTime + mLinearAcceleration * elapsedTime * elapsedTime * 0.5f;

	//vitesse linéaire
	mLinearVelocity +=  mLinearAcceleration * elapsedTime;

	//position angulaire
	mAngularPosition += mAngularVelocity * elapsedTime + mAngularAcceleration * elapsedTime * elapsedTime * 0.5f;

	//vitesse angulaire
	mAngularVelocity += mAngularAcceleration * elapsedTime;
	
	reset();
}
