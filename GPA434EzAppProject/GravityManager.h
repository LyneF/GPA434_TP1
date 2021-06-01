#pragma once
#ifndef GRAVITYMANAGER_H
#define GRAVITYMANAGER_H

#include <EzApp>
#include "Vect2D.h"
#include "Polygon.h"


class GravityManager
{
private:
	float mGravityStrength;
	Vect2D mGravity;
	Polygon mShape;
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

	// Keyboard management
	void update(ezapp::Keyboard const& keyboard);

	// draw
	void draw(ezapp::Screen& screen);
};

#endif //GRAVITYMANAGER_H