#pragma once
#ifndef GRAVITYMANAGER_H
#define GRAVITYMANAGER_H

// Inclusion des biblioth�ques
#include <EzApp>
#include "Vect2D.h"
#include "Body.h"

//Classe permettant de g�rer l'effet de gravit� ajout� au jeu
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
	// Retourne la valeur de la force de la gravit�
	float gravityStrength() const;

	//Retourne le VEct2D repr�sentant la gravit�
	Vect2D gravity() const;



	// ****************Mutateurs****************
	void setGravityStrength(float strength);
	void setShapeOrigin(Vect2D const& shapeOrigin);


	//************Accesseur/Mutateurs***********
	Body& body();

	// Keyboard management
	void update(ezapp::Keyboard const& keyboard);

	// Dessiner � l'�cran
	void draw(ezapp::Screen& screen);
};

#endif //GRAVITYMANAGER_H