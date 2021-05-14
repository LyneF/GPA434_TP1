#include "Shuttle.h"

void Shuttle::control(const Keyboard& keyboard, GameEngine& gameEngine)
{
}

void Shuttle::processTime(float elapsedTime)
{
	mBody.processTime(elapsedTime);

}

void Shuttle::drawOnScreen(Screen& screen)
{
}

bool Shuttle::isColliding(const Asteroid& asteroid)
{
	return false;
}
