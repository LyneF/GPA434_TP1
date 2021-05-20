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

//R�initialisation des param�tres
void Physics::reset()
{
	//Remise � z�ro pour que les acc�l�rations ne soient pas trop grosses
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

//Utiliser des op�rateurs dans Vect2D
//Additionne une acc�l�ration lin�aire � celle d�j� existante
void Physics::applyLinearAcceleration(Vect2D acceleration)
{
	//compos� des float linear et angular?????
	mLinearAcceleration += acceleration;
}

//Additionne une acc�l�ration lin�aire � celle d�j� existante

void Physics::applyLinearAcceleration(float acceleration)
{
	mLinearAcceleration += acceleration;
}

//Additionne une acc�l�ration angulaire � celle d�j� existante
void Physics::applyAngularAcceleration(float acceleration)
{
	mAngularAcceleration += acceleration;
}


//Mise � jour des positions et vitesses selon Newton
void Physics::processTime(float elapsedTime)
{	
	//Formules de Newton
	//position lin�aire
	mLinearPosition += mLinearVelocity * elapsedTime + mLinearAcceleration * elapsedTime * elapsedTime * 0.5f;

	//vitesse lin�aire
	mLinearVelocity +=  mLinearAcceleration * elapsedTime;

	//position angulaire
	mAngularPosition += mAngularVelocity * elapsedTime + mAngularAcceleration * elapsedTime * elapsedTime * 0.5f;

	//vitesse angulaire
	mAngularVelocity += mAngularAcceleration * elapsedTime;
	
	reset();
}
