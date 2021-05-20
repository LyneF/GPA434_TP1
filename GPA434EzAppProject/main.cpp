// Inclusion de la librairie EzApp
#include <EzApp>
// Il est recommandé de consulter la documentation de la librairie EzApp. 
// Il suffit d'ouvrir le fichier index.html se trouvant dans le sous-dossier :
//  /EzApp/Doc/
//
// Il est aussi pertinent d'aller voir les fichiers *.h où sont déclarées 
// les classes de la librairie EzApp :
//  - ezapp::Application
//  - ezapp::Keyboard
//  - ezapp::Screen
//  - ezapp::Timer
//  - ezapp::PolygonUtilities

#include "Color.h"
#include "Vect2D.h"
#include "Polygon.h"
#include "GameEngine.h"
#include <iostream>

// Fonction correspondant au point d'entré du programme.
int WinMain() 
{
    //Vect2D v1, v2(1.0f, 2.0f), v3(-1.0f, 0.5f), v4;
    ////v1 = v4.add(v2.add(v3));
    //v1 = v4 - v2 + v3;
    //v1 = v2 * 2.0f;
    //v1 = v2 / 2.0f;
    //v1 = -v2;
    //bool test{ v1 == v2 };
    //bool test2{ v1 != v2 };
    //v1 += v2;

    //v1 = v2 + v3;
    //v1 = v3 + v2;
    //v1 = v2 * 5.0f;
    //v1 = 5.0f * v2;
    //std::cout << v1 << v2 << v3;

    //std::string s;
    //s = v1.toString();

    // Define default parameters
    size_t const windowWidth{ 1200 };
    size_t const windowHeight{ 1000 };
    std::string const title("GPA434 Projet 1");
    std::string const iconFilename("GPALogo.png");
    std::list<std::string> const fontFilename({ "Arial" });

    // Define main application and setup parameters
    ezapp::Application::Parameters param(windowWidth, windowHeight, title, iconFilename, fontFilename);
    ezapp::Application app(param);

    GameEngine game;

    // Run application
    app.run(game, &GameEngine::processEvents, &GameEngine::processDisplay);

    // End the program
    return 0;
}


double globalTime{};
#include <cmath>





