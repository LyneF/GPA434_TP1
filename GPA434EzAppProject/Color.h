#ifndef COLOR_H
#define COLOR_H

enum Colors {
	RED = 0xFF0000, GREEN = 0x00FF00, BLUE = 0x0000FF,
	VESSEL = 0x7F7FFF, BLACK = 0xFFFFFF, WHITE = 0x000000,
	SCREEN = 0xFFFF00, BORDER = 0xFF7F00
};

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

	//Fonction pour convertir la couleur en hex
	void convertColor(unsigned color);

public:
	Color();
	Color(unsigned color, float alpha = 1.0f);
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
	void setColor(unsigned color, float alpha = 1.0f);

	// Fonctions utilitaires
	void randomize(bool randomizeAlpha = false);
	// void blend(Color color, float factor = 0.5f); // TO DO


	// Lien avec la librairie EzApp
	void setPen(ezapp::Screen& screen, float width);
	void setBrush(ezapp::Screen& screen);

};

#endif // COLOR_H