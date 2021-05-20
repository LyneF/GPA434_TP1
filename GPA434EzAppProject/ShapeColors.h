#pragma once
#ifndef SHAPECOLORS_H
#define SHAPECOLORS_H

#include <EzApp>
#include "Color.h"

class ShapeColors
{
private:
	Color mBrushColor{ };
	Color mPenColor{ };
	float mPenWidth{ 1.0 };


public:
	void setBrushColor(float color);
	void setPenColor(float color);
	void setPenWidth(float width);
};

#endif //SHAPECOLORS_H