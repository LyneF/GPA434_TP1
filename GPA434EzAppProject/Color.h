#ifndef COLOR_H
#define COLOR_H

//�num�ration des couleurs utilis�es durant tout le projet avec leur composantes en hex
enum Colors {
	RED = 0xFF0000, GREEN = 0x00FF00, BLUE = 0x0000FF,
	VESSEL = 0x7F7FFF, WHITE = 0xFFFFFF, BLACK = 0x000000,
	YELLOW = 0xFFFF00, CYAN = 0x00FFFF, MAGENTA = 0xFF00FF,
	SCREEN = 0xFFFF00, BORDER = 0xFF7F00, MISSILE = 0xEB5534,
	LIGHTBLUE = 0x3F3FFF, ASTEROID = 0x86878A
};

// Inclusion des biblioth�ques
#include <EzApp>

// Classe repr�sentant la couleur avec ses 4 valeurs normalis�es 0.0-1.0.
//   r
//   g
//   b
//   a


//Calsse permettant d'utiliser diff�renets couleurs pour l'affichage du jeu Ast�roide
class Color
{
public:
	// Cr�ation du type couleur
	using couleur = float;

private:
	couleur mRed, mGreen, mBlue, mAlpha;

	//Fonction pour convertir la couleur en hex
	void convertColor(unsigned color);

public:
	Color();
	Color(unsigned color, couleur alpha = 1.0f);
	~Color() = default;
	//Op�rateur d'assignation
	Color& operator=(Color const& rhs) = default; 
	//Constructeur de copie
	Color(Color const& color) = default; 

	// Accesseurs
	//Retour de la couleur rouge
	couleur red() const;

	// Retour de la couleur vert
	couleur green() const;

	// Retour de la couleur bleu
	couleur blue() const;

	// Retour de l'opacit�
	couleur alpha() const;


	// Mutateurs
	// Assignation de la couleur rouge � une valeur dans l'intervalle d�di� 
	void setRed(couleur red);
	// Assignation de la couleur vert � une valeur dans l'intervalle d�di� 
	void setGreen(couleur green);
	// Assignation de la couleur bleu � une valeur dans l'intervalle d�di� 
	void setBlue(couleur blue);
	// Assignation de l'opacit� � une valeur dans l'intervalle d�di� 
	void setAlpha(couleur alpha);
	// Assignation d'une couleur � une valeur dans l'intervalle d�di� avec une opacit� d�clar�e � 1.0 par d�faut
	void setColor(unsigned color, couleur alpha = 1.0f);


	// Fonctions utilitaires
	// Assignation de valeurs al�atoires dans l'intervalle d�di� pour les couleurs rouge, vert et bleu de Color
	// en assigant l'opacit� � false par d�faut
	void randomize(bool randomizeAlpha = false);

	// Assignation statique de valeurs al�atoires dans l'intervalle d�di� pour les couleurs rouge, vert et bleu de Color
	// en assigant l'opacit� � false par d�faut
	static Color randomized(bool randomizeAlpha = false);


	// void blend(Color color, float factor = 0.5f); // TO DO


	// Lien avec la librairie EzApp
	void setScreenPen(ezapp::Screen& screen, float width);
	void setScreenBrush(ezapp::Screen& screen);

};

#endif // COLOR_H