#ifndef VECT2D_H
#define VECT2D_H

// Inclusion des biblioth�ques
#include "Random.h"
#include <cmath>
#include <ostream>
#include <sstream>
#include <string>

class Vect2D;
std::ostream& operator<<(std::ostream& lhs, Vect2D const& rhs);

//	Classe permettant de g�rer toutes les utilisations pratiques pour les
//	vecteurs dirigeant les diff�rents composant du jeu
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

	//Op�rateur d'assignation
	Vect2D& operator=(Vect2D const& rhs) = default;

	//Constructeur de copie
	Vect2D(Vect2D const& rhs) = default;

	// ****************Accesseurs****************
	// Retourne la longueur du vecteur au carr� si elle est positive
	bool isValid() const { return lengthSquared() > 0.0f; }

	// Retourne le vecteur s'il est un vecteur unitaire
	bool isUnit() const { return lengthSquared() == 1.0f; }

	//Retourne le la composante en X du pointeur this
	float x() const { return (*this).mX; }

	//Retourne le la composante en Y du pointeur this
	float y() const { return this->mY; }


	// ****************Mutateurs****************
	// Variable du Vect2D en X modifi�e pour x
	void setX(float x) { mX = x; }

	// Variable du Vect2D en Y modifi�e pour y
	void setY(float y) { mY = y; }

	// Variables du Vect2D en X et en Y modifi�e pour x et y
	void set(float x, float y) { setX(x); setY(y); }

	// Mise � 0 des variables X et Y du Vect2D
	void reset() { setX(0.0f); setY(0.0f); }


	// ****************Representation polaire
	//**************** Accesseurs****************
	//Retourne la longueur du vecteur au carr� 
	float lengthSquared() const { return mX * mX + mY * mY; }

	//Retourne la longueur du vecteur
	float length() const { return std::sqrt(lengthSquared()); }

	//Retourne l'orientation du vecteur en radians
	float orientation() const { return std::atan2(mY, mX); } 

	//Retour du pr�fixe de string
	static std::string prefix() { return mPrefix; }

	//Retour du s�parateur de string
	static std::string separator() { return mSeparator; }

	//Retour du suffixe de string
	static std::string suffix() { return mSuffix; }
	

	// ****************Mutateurs****************
	// Variables X et Y du Vect2d assign�es par la longueur et l'orientation
	void setPolar(float length, float orientation) { // orientation en radians
		mX = length * std::cos(orientation);
		mY = length * std::sin(orientation);
	}

	//Assignation du pr�fixe, du s�parateur et du sufixe pour une string
	static void setFormat(std::string const& prefix, std::string const& separator, std::string const& suffix) {
		mPrefix = prefix;
		mSeparator = separator;
		mSuffix = suffix;
	}
	
	// Distance entre 2 Vect2D
	float distanceSquared(Vect2D const& other) const { return std::pow(other.x() - mX, 2.0f) + std::pow(other.y() - mY, 2.0f); }
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

	// ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
	std::string toString() const {
		std::stringstream stream;
		stream << *this;
		return stream.str();
	}


	// ****************Valeurs al�atoires****************
	//Assignation d'une avriable al�atoire en X pour le Vect2D en 0 et 1
	void randomizeX(float minValue = 0.0f, float maxValue = 1.0f) { mX = Random::real(minValue, maxValue); }

	// Assignation d'une avriable al�atoire en Y pour le Vect2D en 0 et 1
	void randomizeY(float minValue = 0.0f, float maxValue = 1.0f) { mY = Random::real(minValue, maxValue); }

	// Assignation d'une variable al�atoire entre une valeur minimale et une valeur maximale
	void randomize(float minValue, float maxValue) { randomize(minValue, maxValue, minValue, maxValue); }

	// Assignation de deux variables al�atoires en X et en Y entre des valeurs minimales et des valeurs maximales pour chaque
	void randomize(float minXValue, float maxXValue, float minYValue, float maxYValue) {
		randomizeX(minXValue, maxXValue);
		randomizeY(minYValue, maxYValue);
	}

	// Retourne un Vect2D cr�� avec 4 valeur al�atoires en X et en Y entre des valeurs minimales et maximales
	static Vect2D randomized(float minXValue, float maxXValue, float minYValue, float maxYValue) {
		Vect2D vect;
		vect.randomize(minXValue, maxXValue, minYValue, maxYValue);
		return vect;
	}

	// Retourne quatres valeurs al�atoires entre une valeur minimale et une valeur maximale
	static Vect2D randomized(float minValue, float maxValue) {
		return randomized(minValue, maxValue, minValue, maxValue);
	}


	// ****************Op�rateurs****************
	// lhs => left hand side
	// rhs => right hand side
	// lhs + rhs
	// Op�ration de soustraction des compsoantes X et Y d'un Vect2D
	Vect2D operator-() const { return Vect2D(-mX, -mY); }

	// Op�rations d'addidtion et de soustraction des composantes X et Y d'un vect 2D avec un autre Vect2D 
	Vect2D operator+(Vect2D const& rhs) const { return Vect2D(mX + rhs.mX, mY + rhs.mY); }
	Vect2D operator-(Vect2D const& rhs) const { return Vect2D(mX - rhs.mX, mY - rhs.mY); }

	// Op�rations de multiplication et de division des composantes X et Y d'un vect 2D avec un des float
	Vect2D operator*(float rhs) const { return Vect2D(mX * rhs, mY * rhs); }
	Vect2D operator/(float rhs) const { return Vect2D(mX / rhs, mY / rhs); } // la division par z�ro doit �tre g�r�e � l'ext�rieur

	// Retour des composantes X et Y d'un Vect2D s'ils correspondent � l'autre Vect2D 
	bool operator==(Vect2D const& rhs) const { return mX == rhs.mX && mY == rhs.mY; }

	// Retour des composantes X et Y d'un Vect2D s'ils ne correspondent pas � l'autre Vect2D 
	bool operator!=(Vect2D const& rhs) const { return mX != rhs.mX || mY != rhs.mY; }

	// Retour de this s'il ne correspond pas � l'autre Vect2D 
	//bool operator!=(Vect2D const& rhs) const { return !(*this == rhs); }
	//bool operator!=(Vect2D const& rhs) const { return !operator==(rhs); }

	// Op�rations d'addidtion et de soustraction des pointeurs d'un Vect2D des composantes X et Y avec un autre Vect2D 
	Vect2D& operator+=(Vect2D const& rhs) { mX += rhs.mX; mY += rhs.mY; return *this; }
	Vect2D& operator-=(Vect2D const& rhs) { mX -= rhs.mX; mY -= rhs.mY; return *this; }

	//Op�ration d'addition des composantes X et Y d'un Vect2D et de float 
	Vect2D operator+=(float const& rhs) const { return Vect2D(mX + rhs, mY + rhs); }

	// Op�rations de multiplication et de division des pointeurs d'un Vect2D des composantes X et Y avec des float
	Vect2D& operator*=(float rhs) { mX *= rhs; mY *= rhs; return *this; }
	Vect2D& operator/=(float rhs) { mX /= rhs; mY /= rhs; return *this; }

};

//??????????????????????????????????????????????????????????????????????????????????????????????????????????
//Vect2D operator*(float lhs, Vect2D const & rhs) { return Vect2D(rhs.x() * lhs, rhs.y() * lhs); }
inline Vect2D operator*(float lhs, Vect2D const& rhs) { return rhs * lhs; }
inline Vect2D operator/(float lhs, Vect2D const& rhs) { return rhs / lhs; }


inline std::ostream& operator<<(std::ostream& lhs, Vect2D const& rhs) {
	lhs << Vect2D::mPrefix << rhs.mX << Vect2D::mSeparator << rhs.mY << Vect2D::mSuffix;
	return lhs;
}

#endif // VECT2D_H