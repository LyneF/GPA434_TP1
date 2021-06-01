#include "Physics.h"

//Constructeur
Physics::Physics()
	: mAngularPosition{ 0.0f  },
	mAngularVelocity{ 0.0f },
	mAngularAcceleration{ 0.0f },
	mLinearPosition(),
	mLinearVelocity(),
	mLinearAcceleration()
{
}

//Faut-il rajouter les vect2d
Physics::Physics(float AngularPosition, float AngularVelocity, float AngularAcceleration)
{
	mAngularPosition = AngularPosition;
	mAngularVelocity = AngularVelocity;
	mAngularAcceleration = AngularAcceleration;
}

//Destructeur
/*Physics:: ~Physics() // ne fait rien
{
}*/

//Réinitialisation des paramètres
void Physics::reset()
{
	//Remise à zéro pour que les accélérations ne soient pas trop grosses
	mAngularAcceleration = 0.0f;
	mLinearAcceleration.reset();
}

Vect2D Physics::getLinearPosition() const
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
Vect2D Physics::getLinearVelocity() const
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
Vect2D Physics::getLinearAcceleration() const
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

void Physics::setPosition(Vect2D const& position)
{
	mLinearPosition = position;
}

void Physics::setVelocity(Vect2D const& velocity)
{
	mLinearVelocity = velocity;
}

void Physics::setAcceleration(Vect2D const& acceleration)
{
	mLinearAcceleration = acceleration;
}


//Utiliser des opérateurs dans Vect2D
//Additionne une accélération linéaire à celle déjà existante
void Physics::applyLinearAcceleration(Vect2D const& acceleration)
{
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


//Valider que c'est bine seulement linear position, pas angularposition
void Physics::manageBorder(float left, float top, float right, float bottom)
{
	if (mLinearPosition.x() < left) {
		mLinearPosition.setX(right + mLinearPosition.x());
	}
	else if (mLinearPosition.x() > right) {
		mLinearPosition.setX(left + mLinearPosition.x() - right);
	}
	if (mLinearPosition.y() < top) {
		mLinearPosition.setY(bottom + mLinearPosition.y());
	}
	else if (mLinearPosition.y() > bottom) {
		mLinearPosition.setY(top + mLinearPosition.y() - bottom);
	}
}