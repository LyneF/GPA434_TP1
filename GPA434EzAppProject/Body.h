#ifndef _BODY_H_
#define _BODY_H_

#include <EzApp>
#include "Physics.h"
#include "Polygon.h"

class Body
{
private:
	Physics mPhysics; 
	Polygon mPolygon;
	size_t mBouncingCount;
	float mRadius;

public:

	Body(float radius = 10.0f, unsigned outlineColor = BLACK, unsigned fillColor = WHITE); 	//ceci est un constructeur par défaut!!!
	~Body() = default;

	//Pour valider si un astéroide doit être enlevé du jeumPhysics
	bool isToBeRemoved() const;

	//Accesseurs
	Polygon& polygon();
	Physics& physics();
	float& radius();

	//Mutateurs
	void reset();

	void setBody(Physics const& body);
	void setRadius(float radius);
	void setColors(unsigned outlineColor, unsigned fillColor);

	void applyLinearAcceleration(Vect2D const& acceleration);
	void applyLinearAcceleration(float acceleration);
	void applyAngularAcceleration(float acceleration);

	void processTime(float elapsedTime);
	void drawOnScreen(ezapp::Screen& screen);

	void randomize(float left, float top, float right, float bottom, float maxSpeed, float minRadius, float maxRadius);
	void bounceBorder(float left, float top, float right, float bottom);

	//Vérifier si les positions de l'astéro et du body other sont pareilles
	bool isColliding(Body other); //ezapp: polygonUtilities intersectPolygon
};

#endif //_BODY_H_
