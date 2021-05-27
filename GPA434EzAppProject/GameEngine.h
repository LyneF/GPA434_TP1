#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <EzApp>
#include "Color.h"
#include "Vect2D.h"
#include "Polygon.h"
#include "ShapeColors.h"

class GameEngine
{
private:
	double mTime;
	Polygon mPentagon;
	Color mFillColor;
	Color mOutlineColor;			//� remplacer par ShapeColor qqch;
	Vect2D mPentagonPosition;
	float mPentagonOrientation;
	float mPentagonSize;

public:
	GameEngine();
	~GameEngine();

	// D�claration des fonctions appel�es � chaque pas de simulation. 
	// 
	// Cette fonction a pour objectif de faire les traitements li�s � la simulation 
	// selon les �v�nements au clavier et le temps �coul�.
	bool processEvents(ezapp::Keyboard const& keyboard, ezapp::Timer const& timer);

	// Cette fonction a pour objectif de faire l'affichage de la simulation � l'�cran.
	void processDisplay(ezapp::Screen& screen);

};

#endif // GAME_ENGINE_H