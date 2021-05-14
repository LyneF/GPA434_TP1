#include "Physics.h"

//à adapter pour .cpp
//Constructeur
Physics::Physics(){}
Physics::Physics(float AngularPosition, float AngularVelocity, float AngularAcceleration) : mAngularPosition{ }, mAngularVelocity{ }, mAngularAcceleration{ }{}
~Physics::Physics(){} // ne fait rien

//Mise à zéro des paramètres (bon terme?)
void Physics::reset()
{
	mLinearPosition.set(0.0f, 0.0f);
	mLinearVelocity.set(0.0f, 0.0f);
	mLinearAcceleration.set(0.0f, 0.0f);
	mAngularAcceleration = 0.0f;
	mAngularPosition = 0.0f;
	mAngularVelocity = 0.0f;
}

//Additionne une accélération linéaire à celle déjà existante
void Physics::applyLinearAcceleration(Vect2D acceleration)
{
	//composé des float linear et angular?????
	mLinearAcceleration.x += acceleration.x;
	mLinearAcceleration.y += acceleration.y;
}

//Additionne une accélération linéaire à celle déjà existante
void Physics::applyLinearAcceleration(float acceleration)
{
	mLinearAcceleration.x += acceleration.x;
	mLinearAcceleration.y += acceleration.y;
}

//Additionne une accélération angulaire à celle déjà existante
void Physics::applyAngularAcceleration(float acceleration)
{
	mLinearAcceleration.x += acceleration.x;
	mLinearAcceleration.y += acceleration.y;
}
//Mise à jour des positions et vitesses selon Newton
void Physics::processTime(float elapsedTime)
{
	//pour gérer le départ du jeu en position de départ et à vitesse nulle
	//if (temps = 0) {
	//	formule de newton avec position initiale et vitesse nulle
	//position
	mLinearPosition.x = mLinearVelocity.x
	mLinearPosition.y = mLinearVelocity.y
	//vitesse
	}
//pour gérer le reste du jeu selon la position précedente et la vitesse précédente
	else {
	//formules de Newton
	//position
	mLinearPosition = mLinearPosition
	
	//vitesse	
	}
}
