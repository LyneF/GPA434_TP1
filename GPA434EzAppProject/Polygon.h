#ifndef POLYGON_H
#define POLYGON_H

// Inclusion des bibliothèques
#include <EzApp>
#include <vector>
#include "Vect2D.h"
#include "Color.h"
#include "ShapeColors.h"
#include "Screen.h"
#include "Random.h"


//Classe permettant de 
class Polygon
{
private:
	std::vector<Vect2D> mVertices;
	ShapeColors mShapeColors;
	float mOutlineWidth{ 1.0f };

public:
	Polygon();
	~Polygon() = default;

	// ****************Accesseurs****************
	size_t verticesCount() const;
	std::vector<Vect2D> vertices() const;

	// ****************Mutateurs****************
	void setVerticesCount(size_t count);
	void setVertex(size_t index, Vect2D const & vertex);
	void setVertices(std::vector<Vect2D> const & vertices);
	void setOutlineWidth();
	//Random& valeur();
	void setBrushColor(unsigned color, float alpha = 1.0f);
	void setPenColor(unsigned color, float alpha = 1.0f);

	//************Accesseurs/Mutateurs************
	ShapeColors& shapeColors();
	float& outlineWidth();

	//************Fonctions utilitaires************
	void buildSquare(float length);
	void buildRectangle(float width, float height);
	void buildRegular(size_t numberOfSides, float circumbscribedRadius);
	void buildCircle(float radius, size_t resolution = 16);
	void buildTriangle(float width, float height);

	//************Fonctions pour le jeu************
	void buildVessel();
	void buildAsteroid();
	void buildMissile();
	void buildStar(size_t numberOfSpikes, float circumbscribedRadius);
	void build7PointsArrow(float x, float y, float length, float width, float lipRatio, float tailWidthRatio);

	// Lien avec la librairie EzApp
	void draw(ezapp::Screen & screen, float x = 0.0f, float y = 0.0f, float rotation = 0.0f, float scale = 1.0f);
};


#endif // POLYGON_H