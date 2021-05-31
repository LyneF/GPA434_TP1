#include "Polygon.h"
#include <cmath>
#include <algorithm>
#include <random>
#include <time.h>

//Écran: 1024 * 768

Polygon::Polygon()
	:mShapeColors()
{
	//Construire un polygone de x côtés avec y comme angle
	buildRegular(3, 1.0f);
}

/*Polygon::~Polygon()
{
	// ne fait rien!!
}*/

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

Color& Polygon::fillColor()
{
	//return mShapeColors.getBrushColor();
}

Color& Polygon::outlineColor()
{
	//return mShapeColors.getPenColor();
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

void Polygon::buildTriangle(float width, float height)
{
	buildRegular(3, width);
}

void Polygon::buildVessel()
{
	//Vaisseau plus sophistiqué (identique à celui du prof)

	float width{ 32.0f }, height{ 34.0f };

	mVertices.resize(22);
	mVertices[0].set(0, height * 12 / 17);
	mVertices[1].set(-width / 16, height * 8 / 17);
	mVertices[2].set(-width / 16, height * 6 / 17);
	mVertices[3].set(-width * 3 / 16, height * 2 / 17);
	mVertices[4].set(-width / 2, 0);
	mVertices[5].set(-width / 2, -height * 2 / 17);
	mVertices[6].set(-width * 3 / 16, -height * 2 / 17);
	mVertices[7].set(-width * 3 / 16, -height * 4 / 17);
	mVertices[8].set(-width * 5 / 16, -height * 7 / 17);
	mVertices[9].set(-width * 3 / 16, -height * 7 / 17);
	mVertices[10].set(-width / 16, -height * 5 / 17);
	mVertices[11].set(0, -height * 6 / 17);
	mVertices[12].set(width / 16, -height * 5 / 17);
	mVertices[13].set(width * 3 / 16, -height * 7 / 17);
	mVertices[14].set(width * 5 / 16, -height * 7 / 17);
	mVertices[15].set(width * 3 / 16, -height * 4 / 17);
	mVertices[16].set(width * 3 / 16, -height * 2 / 17);
	mVertices[17].set(width / 2, -height * 2 / 17);
	mVertices[18].set(width / 2, 0);
	mVertices[19].set(width * 3 / 16, height * 2 / 17);
	mVertices[20].set(width / 16, height * 6 / 17);
	mVertices[21].set(width / 16, height * 8 / 17);

}

void Polygon::buildAsteroid()
{
	//Initialiser rand()
	srand(time(NULL));

	float radius = valeur.real(15, 25);
	int sides = valeur.integer(4, 8);

	const float pi{ 3.1415926535897932384626433832795f };

	mVertices.resize(sides);
	for (int i{}; i < sides; ++i) {
		float theta{ i * valeur.real(2,4) * pi / sides };
		mVertices[i].set(std::cos(theta) * radius,
			std::sin(theta) * radius);
	}

}

void Polygon::buildMissile()
{
	mVertices.resize(22);

	//À FAIRE

}


void Polygon::draw(ezapp::Screen& screen, float x, float y, float rotation, float scale)
{
	screen.setPolygonVertices(mVertices);
	screen.drawPolygon(x, y, rotation, scale);
}
