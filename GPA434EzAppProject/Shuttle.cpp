#include "Shuttle.h"


Shuttle::Shuttle()
{
    mBody.polygon().buildVessel();
}

/*Shuttle::~Shuttle()
{
	// ne fait rien!!
}*/

//Fonction qui existait d�j�!!!!!!!!!!!!! 
void Shuttle::control(const ezapp::Keyboard& keyboard, GameEngine& gameEngine)
{
}

//Fonction qui existait d�j�!!!!!!!!!!!!! 
void Shuttle::processTime(float elapsedTime)
{
	mBody.processTime(elapsedTime);

}

//Fonction qui existait d�j�!!!!!!!!!!!!! 
void Shuttle::drawOnScreen(ezapp::Screen& screen, Vect2D mShuttlePosition,
    float mShuttleOrientation, float mShuttleSize)
{
    mBody.polygon().setBrushColor(VESSEL, 1.0f);
    mBody.polygon().setPenColor(WHITE, 1.0f);
    mBody.polygon().draw(screen, mShuttlePosition.x(), mShuttlePosition.y(),
        mShuttleOrientation, mShuttleSize);
}

//Fonction qui existait d�j�!!!!!!!!!!!!! 
bool Shuttle::isColliding(const Asteroid& asteroid)
{
	return false;
}

