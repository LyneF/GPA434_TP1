#ifndef VECT2D_H
#define VECT2D_H


#include <cmath>
#include <ostream>
#include <sstream>
#include <string>

class Vect2D;
std::ostream& operator<<(std::ostream& lhs, Vect2D const& rhs);

class Vect2D
{
	friend std::ostream& operator<<(std::ostream& lhs, Vect2D const& rhs);

private:
	float mX, mY;// pour EzApp
	static std::string mPrefix, mSeparator, mSuffix;

public:
	Vect2D() 
		: Vect2D(0.0f, 0.0f) {}
	Vect2D(float x, float y)
		: mX{ x }, mY{ y } {}
	~Vect2D() = default; // ne fait rien
	Vect2D& operator=(Vect2D const& rhs) = default;
	Vect2D(Vect2D const& rhs) = default;

	// Accesseurs
	bool isValid() const { return lengthSquared() > 0.0f; }
	bool isUnit() const { return lengthSquared() == 1.0f; }
	float x() const { return (*this).mX; }
	float y() const { return this->mY; }

	// Mutateurs
	void setX(float x) { mX = x; }
	void setY(float y) { mY = y; }
	void set(float x, float y) { setX(x); setY(y); }
	void reset() { setX(0.0f); setY(0.0f); }

	// Representation polaire
	// Accesseurs
	float lengthSquared() const { return mX * mX + mY * mY; }
	float length() const { return std::sqrt(lengthSquared()); }
	float orientation() const { return std::atan2(mY, mX); } // radians

	static std::string prefix() { return mPrefix; }
	static std::string separator() { return mSeparator; }
	static std::string suffix() { return mSuffix; }
	
	// Mutateurs
	void setPolar(float length, float orientation) { // orientation en radians
		mX = length * std::cos(orientation);
		mY = length * std::sin(orientation);
	}
	static void setFormat(std::string const& prefix, std::string const& separator, std::string const& suffix) {
		mPrefix = prefix;
		mSeparator = separator;
		mSuffix = suffix;
	}
	
	// Distance entre 2 Vect2D
	float distanceSquared(Vect2D const& other) const { return std::pow(other.x() - mX, 2.0) + std::pow(other.y() - mY, 2.0); }
	float distance(Vect2D const& other) const { return std::sqrt(distanceSquared(other)); }

	// Vecteur unitaire
	void normalize() {
		if (isValid()) {
			float len{ length() };
			mX /= len;
			mY /= len;
		}
	}
	Vect2D normalized() {
		Vect2D vec;
		vec.set(mX, mY);
		vec.normalize();
		return vec;
	}

	std::string toString() const {
		std::stringstream stream;
		stream << *this;
		return stream.str();
	}

	// Valeurs aléatoires
	// TO DO
	// void randomizeX(float minValue = 0.0f, float maxValue = 1.0f);
	// void randomizeY(float minValue = 0.0f, float maxValue = 1.0f);
	// void randomize(float minValue = 0.0f, float maxValue = 1.0f);
	// void randomize(float minXValue = 0.0f, float maxXValue = 1.0f, float minYValue = 0.0f, float maxYValue = 1.0f);

	// Opérateurs
	// lhs => left hand side
	// rhs => right hand side
	// lhs + rhs
	Vect2D operator-() const { return Vect2D(-mX, -mY); }

	Vect2D operator+(Vect2D const& rhs) const { return Vect2D(mX + rhs.mX, mY + rhs.mY); }
	Vect2D operator-(Vect2D const& rhs) const { return Vect2D(mX - rhs.mX, mY - rhs.mY); }

	Vect2D operator*(float rhs) const { return Vect2D(mX * rhs, mY * rhs); }
	Vect2D operator/(float rhs) const { return Vect2D(mX / rhs, mY / rhs); }// la division par zéro doit être gérée à l'extérieur


	bool operator==(Vect2D const& rhs) const { return mX == rhs.mX && mY == rhs.mY; }
	bool operator!=(Vect2D const& rhs) const { return mX != rhs.mX || mY != rhs.mY; }
	//bool operator!=(Vect2D const& rhs) const { return !(*this == rhs); }
	//bool operator!=(Vect2D const& rhs) const { return !operator==(rhs); }

	Vect2D& operator+=(Vect2D const& rhs) { mX += rhs.mX; mY += rhs.mY; return *this; }
	Vect2D& operator-=(Vect2D const& rhs) { mX -= rhs.mX; mY -= rhs.mY; return *this; }
	Vect2D operator+=(float const& rhs) const { return Vect2D(mX + rhs, mY + rhs); }
	Vect2D& operator*=(float rhs) { mX *= rhs; mY *= rhs; return *this; }
	Vect2D& operator/=(float rhs) { mX /= rhs; mY /= rhs; return *this; }

};

//Vect2D operator*(float lhs, Vect2D const & rhs) { return Vect2D(rhs.x() * lhs, rhs.y() * lhs); }
inline Vect2D operator*(float lhs, Vect2D const& rhs) { return rhs * lhs; }
inline Vect2D operator/(float lhs, Vect2D const& rhs) { return rhs / lhs; }


inline std::ostream& operator<<(std::ostream& lhs, Vect2D const& rhs) {
	lhs << Vect2D::mPrefix << rhs.mX << Vect2D::mSeparator << rhs.mY << Vect2D::mSuffix;
	return lhs;
}

#endif // VECT2D_H