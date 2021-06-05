#pragma once
#ifndef SHAPECOLORS_H
#define SHAPECOLORS_H

// Inclusion des bibliothèques
#include <EzApp>
#include "Color.h"


//Classe permettant de 
class ShapeColors
{
private:
	Color mBrushColor{ };
	Color mPenColor{ };
	Color mFillColor;
	Color mOutlineColor;
	float mOutlineWidth;
	float mPenWidth{ 1.0f };


public:

	//****************Constructeurs****************
	ShapeColors();
	~ShapeColors();

	// ****************Accesseurs****************
	Color getBrushColor();
	Color getPenColor();
	Color getFillColor();
	Color getOutlineColor();

	//****************Mutateurs****************
	void setBrushColor(unsigned color, float alpha = 1.0f);
	void setPenColor(unsigned color, float alpha = 1.0f);
	void setPenWidth(float width);
	void setFillColor(ezapp::Screen& screen); //TO DO
	void setOutlineColor(ezapp::Screen& screen, float width); //TO DO
};

#endif //SHAPECOLORS_H