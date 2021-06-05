#pragma once
#ifndef GRAVITYMANAGER_H
#define GRAVITYMANAGER_H

// Inclusion des bibliothèques
#include <EzApp>
#include "Vect2D.h"
#include "Body.h"

//Classe permettant de gérer l'effet de gravité ajouté au jeu
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

	// ****************Accesseurs****************
	// Retourne la valeur de la force de la gravité
	float gravityStrength() const;

	//Retourne le VEct2D représentant la gravité
	Vect2D gravity() const;



	// ****************Mutateurs****************
	void setGravityStrength(float strength);
	void setShapeOrigin(Vect2D const& shapeOrigin);


	//************Accesseur/Mutateurs***********
	Body& body();

	// Keyboard management
	void update(ezapp::Keyboard const& keyboard);

	// Dessiner à l'écran
	void draw(ezapp::Screen& screen);
};

#endif //GRAVITYMANAGER_H