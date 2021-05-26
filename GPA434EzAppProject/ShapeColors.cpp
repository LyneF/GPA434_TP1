#include "ShapeColors.h"


ShapeColors::ShapeColors()
	:mBrushColor(0.0f, 0.5f, 0.0f, 1.0f),
	mPenColor(0.0f, 0.0f, 0.5f, 1.0f),
	mPenWidth{ 0.5f }
{
}

ShapeColors::~ShapeColors()
{
}

void ShapeColors::setBrushColor(ezapp::Screen& screen, float red, float green, float blue, float alpha)
{
	mBrushColor.setColor(red, green, blue, alpha);
	mBrushColor.setBrush(screen);
}

void ShapeColors::setPenColor(ezapp::Screen& screen, float red, float green, float blue, float alpha)
{
	mPenColor.setColor(red, green, blue, alpha);
	mPenColor.setPen(screen, mPenWidth);
}

void ShapeColors::setPenWidth(float width)
{
	mPenWidth = width;
}

