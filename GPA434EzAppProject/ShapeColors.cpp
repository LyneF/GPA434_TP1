#include "ShapeColors.h"

ShapeColors::ShapeColors()
	:mBrushColor(WHITE),
	mPenColor(BLACK),
	mPenWidth{ 0.5f }
{
}

ShapeColors::~ShapeColors()
{
}

Color ShapeColors::getBrushColor()
{
	return mBrushColor;
}

Color ShapeColors::getPenColor()
{
	return mPenColor;
}

Color ShapeColors::getFillColor()
{
	return mFillColor;
}

Color ShapeColors::getOutlineColor()
{
	return mOutlineColor;
}

//Changer la couleur du pinceau
void ShapeColors::setBrushColor(unsigned color, float alpha)
{
	mBrushColor.setColor(color, alpha);
}

//Changer la couleur du stylo
void ShapeColors::setPenColor(unsigned color, float alpha)
{
	mPenColor.setColor(color, alpha);
}

void ShapeColors::setPenWidth(float width)
{
	mPenWidth = width;
}

//Envoyer la couleur du pinceau à l'écran
void ShapeColors::setFillColor(ezapp::Screen& screen)
{
	mBrushColor.setScreenBrush(screen);
}

//Enoyer la couleur du stylo à l'écran
void ShapeColors::setOutlineColor(ezapp::Screen& screen, float width)
{
	if ((width <= 0) || (width >= 5.0f))
		width = mPenWidth;
	mPenColor.setScreenPen(screen, width);
}

