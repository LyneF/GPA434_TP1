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

void ShapeColors::setBrushColor(ezapp::Screen& screen, unsigned color, float alpha)
{
	mBrushColor.setColor(color, alpha);
	mBrushColor.setBrush(screen);
}

void ShapeColors::setPenColor(ezapp::Screen& screen, unsigned color, float alpha)
{
	mPenColor.setColor(color, alpha);
	mPenColor.setPen(screen, mPenWidth);
}

void ShapeColors::setPenWidth(float width)
{
	mPenWidth = width;
}

