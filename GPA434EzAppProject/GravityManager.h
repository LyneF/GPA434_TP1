#pragma once
#ifndef GRAVITYMANAGER_H
#define GRAVITYMANAGER_H

#include <EzApp>
#include "Vect2D.h"
#include "Body.h"


class GravityManager
{
private:
	float mGravityStrength;
	Vect2D mGravity;
	Body mBody;
	Vect2D mShapeOrigin;

public:
	GravityManager();
	~GravityManager() = default;

	// Accesseurs
	float gravityStrength() const;
	Vect2D gravity() const;

	// Mutateurs
	void setGravityStrength(float strength);
	void setShapeOrigin(Vect2D const& shapeOrigin);

	//Accesseur/Mutateurs
	Body& body();

	// Keyboard management
	void update(ezapp::Keyboard const& keyboard);

	// draw
	void draw(ezapp::Screen& screen);
};

#endif //GRAVITYMANAGER_H