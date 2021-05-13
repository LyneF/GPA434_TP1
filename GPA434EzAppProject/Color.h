#ifndef COLOR_H
#define COLOR_H


#include <EzApp>


// Classe représentant la couleur avec ses 4 valeurs normalisées 0.0-1.0.
//   r
//   g
//   b
//   a
class Color
{
private:
	float mRed, mGreen, mBlue, mAlpha;

public:
	Color();
	Color(float red, float green, float blue, float alpha = 1.0f);
	~Color();

	// Accesseurs
	float red() const;
	float green() const;
	float blue() const;
	float alpha() const;

	// Mutateurs
	void setRed(float red);
	void setGreen(float green);
	void setBlue(float blue);
	void setAlpha(float alpha);
	void setColor(float red, float green, float blue, float alpha = 1.0f);

	// Fonctions utilitaires
	void randomize(bool randomizeAlpha = false);
	// void blend(Color color, float factor = 0.5f); // TO DO


	// Lien avec la librairie EzApp
	void setPen(ezapp::Screen& screen);
	void setBrush(ezapp::Screen& screen);

};




#endif // COLOR_H