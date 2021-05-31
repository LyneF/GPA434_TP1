#include "Color.h"

#include <random>
#include <algorithm>


void Color::convertColor(unsigned color)
{
	//Valider la valeur reçue
	if ((color == 0) || (color > 0xFFFFFF)) {
		mRed = 0.0f;
		mGreen = 0.0f;
		mBlue = 0.0f;
	}
	//Convertir aux couleurs
	else {
		//Répartir la valeur de chaque couleur
		unsigned red = color / 0x10000;
		unsigned green = (color % 0x10000) / 0x100;
		unsigned blue = (color % 0x10000) % 0x100;

		//Convertir en valeur couleur
		mRed = red / 0xFF;
		mGreen = green / 0xFF;
		mBlue = blue / 0xFF;
	}
}

Color::Color()
	: Color(BLACK)
{
}

Color::Color(unsigned color, couleur alpha)
{
	setColor(color, alpha);
}

/*Color::~Color()
{
	// ne fait rien!
}*/

Color::couleur Color::red() const
{
	return mRed;
}

Color::couleur Color::green() const
{
	return mGreen;
}

Color::couleur Color::blue() const
{
	return mBlue;
}

Color::couleur Color::alpha() const
{
	return mAlpha;
}

void Color::setRed(couleur red)
{
	mRed = std::clamp(red, 0.0f, 1.0f);
}

void Color::setGreen(couleur green)
{
	mGreen = std::clamp(green, 0.0f, 1.0f);
}

void Color::setBlue(couleur blue)
{
	mBlue = std::clamp(blue, 0.0f, 1.0f);
}

void Color::setAlpha(couleur alpha)
{
	mAlpha = std::clamp(alpha, 0.0f, 1.0f);
}

void Color::setColor(unsigned color, couleur alpha)
{
	convertColor(color);
	setAlpha(alpha);
}

void Color::randomize(bool randomizeAlpha)
{
	mRed = (couleur)rand() / RAND_MAX;
	mGreen = (couleur)rand() / RAND_MAX;
	mBlue = (couleur)rand() / RAND_MAX;
	mAlpha = randomizeAlpha ? (couleur)rand() / RAND_MAX : 1.0f;
}

//On ne devrait pas les voir plus loin?? Genre dans polygon.h
void Color::setPen(ezapp::Screen& screen, float width)
{
	screen.setPen(mRed, mGreen, mBlue, mAlpha, width);
}

void Color::setBrush(ezapp::Screen& screen)
{
	screen.setBrush(mRed, mGreen, mBlue, mAlpha);
}

