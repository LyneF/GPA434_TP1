#ifndef _BODY_H_
#define _BODY_H_

#include <EzApp>
#include "Physics.h"
#include "Polygon.h"


class Body
{
private:
	Physics mPhysics{ };
	Polygon mShape{ };

public:
	void reset();
	void applyLinearAcceleration(Vect2D acceleration);
	void applyLinearAcceleration(float acceleration);
	void applyAngularAcceleration(float acceleration);
	void processTime(float elapsedTime);
	void drawOnScreen(ezapp::Screen & screen);



	//Vérifier si les positions de l'astéro et du body other sont pareilles
	bool isColliding(Body other); //ezapp: polygonUtilities intersectPolygon
};

#endif //_BODY_H_
