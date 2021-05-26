#include "Color.h"

#include <random>
#include <algorithm>


Color::Color()
	: Color(0.0f, 0.0f, 0.0f, 1.0f)
{
}

Color::Color(float red, float green, float blue, float alpha)
{
	setColor(red, green, blue, alpha);
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

void Color::setColor(float red, float green, float blue, float alpha)
{
	setRed(red);
	setGreen(green);
	setBlue(blue);
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

