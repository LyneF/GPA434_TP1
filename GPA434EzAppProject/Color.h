#ifndef COLOR_H
#define COLOR_H

enum Colors {
	RED = 0xFF0000, GREEN = 0x00FF00, BLUE = 0x0000FF,
	VESSEL = 0x7F7FFF, WHITE = 0xFFFFFF, BLACK = 0x000000,
	YELLOW = 0xFFFF00, CYAN = 0x00FFFF, MAGENTA = 0xFF00FF,
	SCREEN = 0xFFFF00, BORDER = 0xFF7F00, MISSILE = 0xEB5534,
	LIGHTBLUE = 0x3F3FFF, ASTEROID = 0x86878A
};

#include <EzApp>

// Classe représentant la couleur avec ses 4 valeurs normalisées 0.0-1.0.
//   r
//   g
//   b
//   a

class Color
{
public:
	using couleur = float;
private:
	couleur mRed, mGreen, mBlue, mAlpha;

	//Fonction pour convertir la couleur en hex
	void convertColor(unsigned color);

public:
	Color();
	Color(unsigned color, couleur alpha = 1.0f);
	~Color() = default;
	Color& operator=(Color const& rhs) = default; // opérateur d'assignation
	Color(Color const& color) = default; // constructeur de copie

	// Accesseurs
	couleur red() const;
	couleur green() const;
	couleur blue() const;
	couleur alpha() const;

	// Mutateurs
	void setRed(couleur red);
	void setGreen(couleur green);
	void setBlue(couleur blue);
	void setAlpha(couleur alpha);
	void setColor(unsigned color, couleur alpha = 1.0f);

	// Fonctions utilitaires
	void randomize(bool randomizeAlpha = false);
	static Color randomized(bool randomizeAlpha = false);


	// void blend(Color color, float factor = 0.5f); // TO DO


	// Lien avec la librairie EzApp
	void setScreenPen(ezapp::Screen& screen, float width);
	void setScreenBrush(ezapp::Screen& screen);

};

#endif // COLOR_H