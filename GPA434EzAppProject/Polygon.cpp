#include "Polygon.h"


#include <cmath>
#include <algorithm>
#include "Screen.h"


//Écran: 1024 * 768

Polygon::Polygon()
	:mShapeColors()
{
	//Construire un polygone de x côtés avec y comme angle
	buildRegular(3, 1.0f);
}

Polygon::~Polygon()
{
	// ne fait rien!!
}

size_t Polygon::verticesCount() const
{
	return mVertices.size();
}

std::vector<Vect2D> Polygon::vertices() const
{
	return mVertices;
}

void Polygon::setVerticesCount(size_t count)
{
	if (count > 0) {
		mVertices.resize(count);
	}
}

void Polygon::setVertex(size_t index, Vect2D const& vertex)
{
	if (index < mVertices.size()) {
		mVertices[index] = vertex;
	}
}

void Polygon::setVertices(std::vector<Vect2D> const& vertices)
{
	if (vertices.size() >= 3) {
		mVertices = vertices;
	}
}

void Polygon::setBrushColor(ezapp::Screen& screen, float red, float green, float blue, float alpha)
{
	mShapeColors.setBrushColor(screen, red, green, blue, alpha);
}

void Polygon::setPenColor(ezapp::Screen& screen, float red, float green, float blue, float alpha)
{
	mShapeColors.setPenColor(screen, red, green, blue, alpha);
}

void Polygon::buildSquare(float length)
{
	buildRectangle(length, length);
}

void Polygon::buildRectangle(float width, float height)
{
	mVertices.resize(4);
	mVertices[0].set(-width / 2.0f, -height / 2.0f);
	mVertices[1].set( width / 2.0f, -height / 2.0f);
	mVertices[2].set( width / 2.0f,  height / 2.0f);
	mVertices[3].set(-width / 2.0f,  height / 2.0f);
}

void Polygon::buildRegular(size_t numberOfSides, float circumbscribedRadius)
{
	const float pi{ 3.1415926535897932384626433832795f };

	if (numberOfSides >= 3) {
		mVertices.resize(numberOfSides);
		for (int i{}; i < numberOfSides; ++i) {
			float theta{ i * 2.0f * pi / numberOfSides };
			mVertices[i].set(std::cos(theta) * circumbscribedRadius, 
							 std::sin(theta) * circumbscribedRadius);
		}
	}
}

void Polygon::buildCircle(float radius, size_t resolution)
{
	buildRegular(resolution, radius);
}

void Polygon::buildVessel(float circumbscribedRadius)
{
	/*
	* 
	* (float width, float height, float radius, size_t resolution)
		//pourquoi il dessine seulement la dernière forme demandée???--> dans draw, l'appeler plusieurs fois?

		//Création des 4 cercles composants la forme du vaisseau
		//-->Cercle principal
		//draw(screen.drawPolygon(x, y, rotation, scale);
		buildRegular(resolution, radius);

		//-->Petits cercles sous le vaisseau
		//Il faut décaler leur centre
		//draw(screen.drawPolygon(x, y, rotation, scale);
		buildRegular(resolution, radius / 5.0f);
		//draw(screen.drawPolygon(x, y, rotation, scale);
		buildRegular(resolution, radius / 5.0f);
		//draw(screen.drawPolygon(x, y, rotation, scale);
		buildRegular(resolution, radius / 5.0f);

	
		//Création de la base du vaisseau
		mVertices.resize(9);
		mVertices[0].set(-width / 4.0f, 0.0f);
		mVertices[1].set((-width / 2.0f)+1.0f, -height / 4.0f);
		mVertices[2].set(-width / 2.0f, (-height /2.0f) + 1.5f);
		mVertices[3].set((-width / 4.0f)+1.0f, (-height / 2.0f)-3.5f);
		mVertices[4].set(0.0f,(-height / 2.0f)-5.0f);
		mVertices[5].set((width / 5.0f) + 1.0f, (-height / 2.0f)-3.5f);
		mVertices[6].set(width / 2.0f, (-height / 2.0f) + 1.5f);
		mVertices[7].set((width / 2.0f) + 1.0f, -height / 4.0f);
		mVertices[8].set(width / 4.0f, 0.0f);
	*/

	mVertices.resize(5);
	mVertices[0].set(std::cos(180) * circumbscribedRadius,
					std::sin(180) * circumbscribedRadius);
	mVertices[1].set(std::cos(70) * circumbscribedRadius,
					std::sin(70) * circumbscribedRadius);
	mVertices[2].set(std::cos(70) * circumbscribedRadius,
					std::sin(70) * circumbscribedRadius);
	mVertices[3].set(std::cos(40) * circumbscribedRadius,
					std::sin(40) * circumbscribedRadius);
	mVertices[4].set(std::cos(40) * circumbscribedRadius,
					std::sin(40) * circumbscribedRadius);
}

void Polygon::buildTriangle(float width, float height)
{
	buildRegular(3, width);
	//mVertices.resize(3);
	//mVertices[0].set(-width / 2.0f, -height / 2.0f);
	//mVertices[1].set(width / 2.0f, -height / 2.0f);
	//mVertices[2].set(0.0f, height / 2.0f);
}

void Polygon::draw(ezapp::Screen& screen, float x, float y, float rotation, float scale)
{
	screen.setPolygonVertices(mVertices);
	screen.drawPolygon(x, y, rotation, scale);
	
	//pour dessiner les 5 polygones au total, avec un tab?
	//screen.drawPolygon(x, y, rotation, scale);
	//screen.drawPolygon(x, y, rotation, scale);
	//screen.drawPolygon(x, y, rotation, scale);
	//screen.drawPolygon(x, y, rotation, scale);
}
