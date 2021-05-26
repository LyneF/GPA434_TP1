#ifndef POLYGON_H
#define POLYGON_H


#include <EzApp>
#include <vector>
#include "Vect2D.h"
#include "ShapeColors.h"


class Polygon
{
private:
	std::vector<Vect2D> mVertices;
	ShapeColors mShapeColors;

public:
	Polygon();
	~Polygon();

	// Accesseurs
	size_t verticesCount() const;
	std::vector<Vect2D> vertices() const;

	// Mutateurs
	void setVerticesCount(size_t count);
	void setVertex(size_t index, Vect2D const & vertex);
	void setVertices(std::vector<Vect2D> const & vertices);
	void setBrushColor(ezapp::Screen& screen, float red, float green, float blue, float alpha = 1.0f);
	void setPenColor(ezapp::Screen& screen, float red, float green, float blue, float alpha = 1.0f);


	// Fonctions utilitaires
	void buildSquare(float length);
	void buildRectangle(float width, float height);
	void buildRegular(size_t numberOfSides, float circumbscribedRadius);
	void buildCircle(float radius, size_t resolution = 16);
	void buildVessel(float circumbscribedRadius);
	void buildTriangle(float width, float height);
	
	//void buildStar(size_t numberOfSpikes, float circumbscribedRadius);

	// Lien avec la librairie EzApp
	void draw(ezapp::Screen & screen, float x = 0.0f, float y = 0.0f, float rotation = 0.0f, float scale = 1.0f);
};


#endif // POLYGON_H