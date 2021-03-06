#include "Polygon.h"
#include <cmath>
#include <algorithm>
#include <random>
#include <time.h>
#include "ShapeColors.h"
#include "Random.h"

//?cran: 1024 * 768

Polygon::Polygon()
	: mVertices()
	, mShapeColors()
	, mOutlineWidth{ 1.0f}
{
	//Construire un polygone de x c?t?s avec y comme angle
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

float& Polygon::outlineWidth()
{
	return mOutlineWidth;
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

//Envoyer ? Shapecolors
void Polygon::setOutlineWidth()
{
	mShapeColors.setPenWidth(mOutlineWidth);
}

ShapeColors& Polygon::shapeColors()
{
	return mShapeColors;
}

/*Random& Polygon::valeur()
{
	return mValeur;
}*/

void Polygon::setBrushColor(unsigned color, float alpha)
{
	mShapeColors.setBrushColor(color, alpha);
}

void Polygon::setPenColor(unsigned color, float alpha)
{
	mShapeColors.setPenColor(color, alpha);
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
	//Vaisseau plus sophistiqu? (identique ? celui du prof)

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

	float radius = Random::real(15, 25);
	int sides = Random::integer(4, 8);

	const float pi{ 3.1415926535897932384626433832795f };

	mVertices.resize(sides);
	for (int i{}; i < sides; ++i) {
		float theta{ i * Random::real(2,4) * pi / sides };
		mVertices[i].set(std::cos(theta) * radius,
			std::sin(theta) * radius);
	}

}

void Polygon::buildMissile()
{
	mVertices.resize(22);

	//? FAIRE

}

/*void Polygon::buildStar(size_t numberOfSpikes, float circumbscribedRadius)
{
	for (int i{}; i < numberOfSpikes; ++i) {
		mVertices[i].set(); //To do
	}
}*/

void Polygon::build7PointsArrow(float x, float y, float length, float width, float lipRatio, float tailWidthRatio) {
/*                     ___ (x, y)
                      /
           _                    _   
          |          ^           |
          |         / \          |
          |        /   \     lipRatio is % from length (0.0f-1.0f)  
          |       /     \        |
        length   /__   __\      _|
          |         | |
          |         | |
          |         | |
          |_        |_|
   
                    |_|________ tailWidthRatio is % from width (0.0f-1.0f)
                 
                 |________|____ width
  */
	lipRatio = std::clamp(lipRatio, 0.05f, 0.95f);
	tailWidthRatio = std::clamp(tailWidthRatio, 0.05f, 0.95f);
	mVertices.resize(7);

	/*si on a le temps: essayer de mieux positionner la fl?che, avec des if pour g?rer les diagonales: placer x,y avec longueur/2, 
	horizontal ajouter la longueur en x, vertical ajouter la longueur en y
	x += length; //pour mieux placer la fl?che ? l'horizontal, faire un if, ? valider
	y += length; //pour mieux placer la fl?che ? la vertical, faire un if, ? valider
	x += length / 2; //pour mieux placer la fl?che ? en diagonal, faire un if, ? valider
	y += length / 2; //pour mieux placer la fl?che ? en diagonal, faire un if, ? valider*/

	mVertices[0].set(x, y);
	mVertices[1].set(x - width / 2.0f, y - length * lipRatio);
	mVertices[2].set(x - width * tailWidthRatio / 2.0f, mVertices[1].y());
	mVertices[3].set(mVertices[2].x(), y - length);
	mVertices[4].set(-mVertices[2].x(), mVertices[3].y());
	mVertices[5].set(mVertices[4].x(), mVertices[1].y());
	mVertices[6].set(-mVertices[1].x(), mVertices[1].y());
}

void Polygon::draw(ezapp::Screen& screen, float x, float y, float rotation, float scale)
{
	mShapeColors.setFillColor(screen);
	mShapeColors.setOutlineColor(screen, mOutlineWidth);
	screen.setPolygonVertices(mVertices);
	screen.drawPolygon(x, y, rotation, scale);
}
