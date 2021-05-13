#ifndef POLYGON_H
#define POLYGON_H

#include <EzApp>
#include <vector>
#include "Vect2D.h"
#include "ShapeColors.h"

class Polygon
{
private:
	//<vector> Vect2D mVertices{ };
	ShapeColors mShapeColors{ };

public:
	void drawOnScreen(ezapp::Screen& screen);

};

#endif // POLYGON_H
