#include "Asteroid.h"


Asteroid::Asteroid()
{
    mBody.polygon().buildAsteroid();
}

/*Asteroid::~Asteroid()
{
    // ne fait rien!!
}*/

//Fonction qui existait déjà!!!!!!!!!!!!! 
float Asteroid::processTime(float elapsedTime)
{
    return 0.0f;
}

void Asteroid::drawOnScreen(ezapp::Screen& screen, Vect2D mAsteroidPosition,
    float mAsteroidOrientation, float mAsteroidSize)
{
    mBody.polygon().setBrushColor(ASTEROID, 1.0f);
    mBody.polygon().setPenColor(ASTEROID, 1.0f);
    mBody.polygon().draw(screen, mAsteroidPosition.x(), mAsteroidPosition.y(),
        mAsteroidOrientation, mAsteroidSize);
}
