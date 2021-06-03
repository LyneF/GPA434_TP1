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
	
	
	
	*/

	float mBodyInsertionTrigger;
	float mTime;
	GravityManager mGravityManager;
	std::vector<Body> mBody;
	Vect2D mShuttlePosition;
	float mShuttleOrientation;
	float mShuttleSize;
	Vect2D mAsteroidPosition;
	float mAsteroidOrientation;
	float mAsteroidSize;

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