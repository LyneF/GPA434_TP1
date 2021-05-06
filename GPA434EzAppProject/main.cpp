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



// Déclaration des fonctions appelées à chaque pas de simulation. 
// 
// Cette fonction a pour objectif de faire les traitements liés à la simulation 
// selon les évènements au clavier et le temps écoulé.
bool processEvents(ezapp::Keyboard const & keyboard, ezapp::Timer const & timer);
// 
// Cette fonction a pour objectif de faire l'affichage de la simulation à l'écran.
void processDisplay(ezapp::Screen & screen);


// Fonction correspondant au point d'entré du programme.
int WinMain() 
{
    // Define default parameters
    size_t const windowWidth{ 1200 };
    size_t const windowHeight{ 1000 };
    std::string const title("GPA434 Projet 1");
    std::string const iconFilename("GPALogo.png");
    std::list<std::string> const fontFilename({ "Arial" });

    // Define main application and setup parameters
    ezapp::Application::Parameters param(windowWidth, windowHeight, title, iconFilename, fontFilename);
    ezapp::Application app(param);

    // Run application
    app.run(processEvents, processDisplay);

    // End the program
    return 0;
}


double globalTime{};
#include <cmath>


bool processEvents(ezapp::Keyboard const & keyboard, ezapp::Timer const & timer) {
    // ...
    double accelerate{ keyboard.isKeyPressed(ezapp::Keyboard::Key::Space) ? 10.0 : 1.0 };
    globalTime += timer.secondSinceLastTic() * accelerate;

    // run until ESCAPE is pressed
    return !keyboard.isKeyPressed(ezapp::Keyboard::Key::Escape);
}

void processDisplay(ezapp::Screen & screen) {
    // Define background color and apply it
    double phaseR{ sin(globalTime * 3.1415) * 0.5 + 0.5};
    double phaseB{ cos(globalTime * 3.1415) * 0.5 + 0.5};
    screen.setBrush(phaseR, 0.45f, phaseB, 1.0f); // opaque medium dark blue grey
    screen.clear();                             // apply color all over the screen

    // ...
}



