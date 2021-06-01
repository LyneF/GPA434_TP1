#ifndef _BODY_H_
#define _BODY_H_

#include <EzApp>
#include "Physics.h"
#include "Polygon.h"
#include "Color.h"


class Body
{
private:
	Physics mBody;  //v�rif: pas initialis�s dans exemple du prof � {}
	Polygon mShape;  //v�rif: pas initialis�s dans exemple du prof � {}
	size_t mBouncingCount;
	float mRadius;

public:

	Body(float radius = 10.0f, Color const& outlineColor = BLACK, Color const& fillColor = WHITE); 	//ceci est un constructeur par d�faut!!!
	~Body() = default;

	//Pour valider si un ast�roide doit �tre enlev� du jeu
	bool isToBeRemoved() const;

	//Accesseurs
	Polygon shape() const;
	Physics body() const;
	float radius() const;

	//Mutateurs
	void reset();

	void setBody(Physics const& body);
	void setRadius(float radius);
	void setColors(Color const& outlineColor, Color const& fillColor);

	void applyLinearAcceleration(Vect2D const& acceleration);
	void applyLinearAcceleration(float acceleration);
	void applyAngularAcceleration(float acceleration);

	void processTime(float elapsedTime);
	void drawOnScreen(ezapp::Screen & screen) const;

	void randomize(float left, float top, float right, float bottom, float maxSpeed, float minRadius, float maxRadius);
	void bounceBorder(float left, float top, float right, float bottom);

	//V�rifier si les positions de l'ast�ro et du body other sont pareilles
	bool isColliding(Body other); //ezapp: polygonUtilities intersectPolygon
};

#endif //_BODY_H_
