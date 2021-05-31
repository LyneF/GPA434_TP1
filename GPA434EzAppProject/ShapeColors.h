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

	//Constructeurs
	ShapeColors();
	~ShapeColors();

	//Accesseurs
	Color getBrushColor();
	Color getPenColor();

	//Mutateurs
	void setBrushColor(ezapp::Screen& screen, unsigned color, float alpha = 1.0f);
	void setPenColor(ezapp::Screen& screen, unsigned color, float alpha = 1.0f);
	void setPenWidth(float width);
};

#endif //SHAPECOLORS_H