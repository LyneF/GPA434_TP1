#include "Physics.h"

//� adapter pour .cpp
//Constructeur
Physics::Physics(){}
Physics::Physics(float AngularPosition, float AngularVelocity, float AngularAcceleration) : mAngularPosition{ }, mAngularVelocity{ }, mAngularAcceleration{ }{}
~Physics::Physics(){} // ne fait rien

//Mise � z�ro des param�tres (bon terme?)
void Physics::reset()
{
	mLinearPosition.set(0.0f, 0.0f);
	mLinearVelocity.set(0.0f, 0.0f);
	mLinearAcceleration.set(0.0f, 0.0f);
	mAngularAcceleration = 0.0f;
	mAngularPosition = 0.0f;
	mAngularVelocity = 0.0f;
}

//Additionne une acc�l�ration lin�aire � celle d�j� existante
void Physics::applyLinearAcceleration(Vect2D acceleration)
{
	//compos� des float linear et angular?????
	mLinearAcceleration.x += acceleration.x;
	mLinearAcceleration.y += acceleration.y;
}

//Additionne une acc�l�ration lin�aire � celle d�j� existante
void Physics::applyLinearAcceleration(float acceleration)
{
	mLinearAcceleration.x += acceleration.x;
	mLinearAcceleration.y += acceleration.y;
}

//Additionne une acc�l�ration angulaire � celle d�j� existante
void Physics::applyAngularAcceleration(float acceleration)
{
	mLinearAcceleration.x += acceleration.x;
	mLinearAcceleration.y += acceleration.y;
}
//Mise � jour des positions et vitesses selon Newton
void Physics::processTime(float elapsedTime)
{
	//pour g�rer le d�part du jeu en position de d�part et � vitesse nulle
	//if (temps = 0) {
	//	formule de newton avec position initiale et vitesse nulle
	//position
	mLinearPosition.x = mLinearVelocity.x
	mLinearPosition.y = mLinearVelocity.y
	//vitesse
	}
//pour g�rer le reste du jeu selon la position pr�cedente et la vitesse pr�c�dente
	else {
	//formules de Newton
	//position
	mLinearPosition = mLinearPosition
	
	//vitesse	
	}
}
