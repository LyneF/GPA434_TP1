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
		mAlpha = 0.0f;
	}
	//Convertir aux couleurs
	else {
		//Répartir la valeur de chaque couleur
		unsigned red = color / 0x10000;
		unsigned green = (color % 0x10000) / 0x100;
		unsigned blue = (color % 0x10000) % 0x100;

		//Convertir en valeur float
		mRed = red / 0xFF;
		mGreen = green / 0xFF;
		mBlue = blue / 0xFF;
	}
}

Color::Color()
	: Color(WHITE)
{
}

Color::Color(unsigned color, float alpha)
{
	setColor(color, alpha);
}

Color::~Color()
{
	// ne fait rien!
}

float Color::red() const
{
	return mRed;
}

float Color::green() const
{
	return mGreen;
}

float Color::blue() const
{
	return mBlue;
}

float Color::alpha() const
{
	return mAlpha;
}

void Color::setRed(float red)
{
	mRed = std::clamp(red, 0.0f, 1.0f);
}

void Color::setGreen(float green)
{
	mGreen = std::clamp(green, 0.0f, 1.0f);
}

void Color::setBlue(float blue)
{
	mBlue = std::clamp(blue, 0.0f, 1.0f);
}

void Color::setAlpha(float alpha)
{
	mAlpha = std::clamp(alpha, 0.0f, 1.0f);
}

void Color::setColor(unsigned color, float alpha)
{
	convertColor(color);
	setAlpha(alpha);
}

void Color::randomize(bool randomizeAlpha)
{
	mRed = (float)rand() / RAND_MAX;
	mGreen = (float)rand() / RAND_MAX;
	mBlue = (float)rand() / RAND_MAX;
	mAlpha = randomizeAlpha ? (float)rand() / RAND_MAX : 1.0f;
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

