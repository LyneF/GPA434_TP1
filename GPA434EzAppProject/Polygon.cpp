#include "Polygon.h"
#include <cmath>
#include <algorithm>
#include "Screen.h"

//�cran: 1024 * 768

Polygon::Polygon()
	:mShapeColors()
{
	//Construire un polygone de x c�t�s avec y comme angle
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

void Polygon::setBrushColor(ezapp::Screen& screen, unsigned color, float alpha)
{
	mShapeColors.setBrushColor(screen, color, alpha);
}

void Polygon::setPenColor(ezapp::Screen& screen, unsigned color, float alpha)
{
	mShapeColors.setPenColor(screen, color, alpha);
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

void Polygon::buildVessel(float width, float height)
{
	/*
	* 
	* (float width, float height, float radius, size_t resolution)
		//pourquoi il dessine seulement la derni�re forme demand�e???--> dans draw, l'appeler plusieurs fois?

		//Cr�ation des 4 cercles composants la forme du vaisseau
		//-->Cercle principal
		//draw(screen.drawPolygon(x, y, rotation, scale);
		buildRegular(resolution, radius);

		//-->Petits cercles sous le vaisseau
		//Il faut d�caler leur centre
		//draw(screen.drawPolygon(x, y, rotation, scale);
		buildRegular(resolution, radius / 5.0f);
		//draw(screen.drawPolygon(x, y, rotation, scale);
		buildRegular(resolution, radius / 5.0f);
		//draw(screen.drawPolygon(x, y, rotation, scale);
		buildRegular(resolution, radius / 5.0f);

	
		//Cr�ation de la base du vaisseau
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

	/*	Vaisseau = triangle qui shoot
		mVertices.resize(7);
		mVertices[0].set(0, circumbscribedRadius/2);
		mVertices[1].set(-circumbscribedRadius / 3, 0);
		mVertices[2].set(-circumbscribedRadius / 10, circumbscribedRadius / 10);
		mVertices[3].set(-circumbscribedRadius / 7, -circumbscribedRadius / 7);
		mVertices[4].set(circumbscribedRadius / 7, -circumbscribedRadius / 7);
		mVertices[5].set(circumbscribedRadius / 10, circumbscribedRadius / 10);
		mVertices[6].set(circumbscribedRadius / 3, 0);
	*/

	//Vaisseau plus sophistiqu�
	mVertices.resize(9);
	mVertices[0].set(0, height * 3/5);
	mVertices[1].set(-width / 6, height * 2/5);
	mVertices[2].set(-width / 6, 0);
	mVertices[3].set(-width / 2, -height * 2/5);
	mVertices[4].set(-width / 6, -height / 5);
	mVertices[5].set(width / 6, -height / 5);
	mVertices[6].set(width / 2, -height * 2/5);
	mVertices[7].set(width / 6, 0);
	mVertices[8].set(width / 6, height * 2/5);
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
