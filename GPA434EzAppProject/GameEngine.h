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
	Color mOutlineColor;			//à remplacer par ShapeColor qqch;
	Vect2D mPentagonPosition;
	float mPentagonOrientation;
	float mPentagonSize;

public:
	GameEngine();
	~GameEngine();

	// Déclaration des fonctions appelées à chaque pas de simulation. 
	// 
	// Cette fonction a pour objectif de faire les traitements liés à la simulation 
	// selon les évènements au clavier et le temps écoulé.
	bool processEvents(ezapp::Keyboard const& keyboard, ezapp::Timer const& timer);

	// Cette fonction a pour objectif de faire l'affichage de la simulation à l'écran.
	void processDisplay(ezapp::Screen& screen);

};

#endif // GAME_ENGINE_H