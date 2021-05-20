#include "Polygon.h"


#include <cmath>
#include <algorithm>


//Écran: 1024 * 768

Polygon::Polygon()
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

void Polygon::draw(ezapp::Screen& screen, float x, float y, float rotation, float scale)
{
	screen.setPolygonVertices(mVertices);
	screen.drawPolygon(x, y, rotation, scale);
}
