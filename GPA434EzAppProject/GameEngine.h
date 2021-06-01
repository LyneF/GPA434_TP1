#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <EzApp>
#include "Color.h"
#include "Vect2D.h"
#include "Polygon.h"
#include "ShapeColors.h"
#include "Body.h"
#include "GravityManager.h"
#include <vector>

class GameEngine
{
private:
	/*double mTime;
	Polygon mShuttle;
	Polygon mAsteroid;
	Polygon mMissile;
	Color mFillColor;
	Color mOutlineColor;			//� remplacer par ShapeColor qqch;
	Vect2D mShuttlePosition;
	Vect2D mAsteroidPosition;
	float mShuttleOrientation;
	float mAsteroidOrientation;
	float mShuttleSize;
	float mAsteroidSize;*/   //pu dans le code de gameengine du prof

	float mBodyInsertionTrigger;
	float mTime;
	GravityManager mGravityManager;
	std::vector<Body> mBody;

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