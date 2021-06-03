#include "GameEngine.h"

/*
GameEngine::GameEngine()
    :mTime{ 0.0f },
    mShuttle(),
    mAsteroid(),
    mFillColor(SCREEN, 1.0f),
    mOutlineColor(BORDER, 1.0f),
    mShuttlePosition(0.0f, 450.0f),
    mAsteroidPosition(0.0f, 450.0f),
    
    mAsteroidOrientation{},
    
    mAsteroidSize{ 2.0f }
{
    mShuttle.
    mAsteroid.buildAsteroid();
}
*/

GameEngine::GameEngine()
    : mBodyInsertionTrigger{}
    , mTime{ 0.0f }
    , mBody(1)
    , mShuttlePosition(0.0f, 450.0f)
    , mShuttleOrientation{}
    , mShuttleSize{ 1.0f }
{
    mGravityManager.setShapeOrigin(Vect2D(1200.0f / 2.0f, 1000.0f / 2.0f));

    for (int i{}; i < mBody.size(); ++i) {
        mBody[i].randomize(0.0f, 1200.0f, 0.0f, 1000.0f, 250.0f, 5.0f, 25.0f);
    }

    mGravityManager.body().polygon().buildVessel();
}

GameEngine::~GameEngine()
{
}

bool GameEngine::processEvents(ezapp::Keyboard const& keyboard, ezapp::Timer const& timer) {
    // Cette partie sera remplacée par des fonctions de Body.h qui incluent les physiques
    double accelerate{ keyboard.isKeyPressed(ezapp::Keyboard::Key::Space) ? 10.0 : 1.0 };
    mTime += timer.secondSinceLastTic() * accelerate;
    mShuttlePosition.set(mTime * 50.0f, 450.0f);
    mShuttleOrientation = mTime;

    //À CHAQUE 10S, RAJOUTER UN ASTEROID DANS LA LISTE
    //À CHAQUE 10S, RAJOUTER UN missile DANS LA LISTE
    //si missile touche à asteroid
    //si vaisseau touche à asteroid

    // run until ESCAPE is pressed
    return !keyboard.isKeyPressed(ezapp::Keyboard::Key::Escape);
}

void GameEngine::processDisplay(ezapp::Screen& screen) {
    //À quoi servent les vecteurs t1 et t2?
    Color mBackground(BLACK, 1.0f);


    // Define background opaque medium dark blue grey color and apply it
    mBackground.setScreenBrush(screen);
    screen.clear();                             // apply color all over the screen

    // ...
   
    ShapeColors screenColor;
    screenColor.setBrushColor(YELLOW, 1.0f);
    screenColor.setFillColor(screen);
    screenColor.setPenColor(BORDER, 1.0f);
    screenColor.setOutlineColor(screen, 1.0f);
    
    //mShuttle.setBrushColor(screen, VESSEL, 1.0f);
    //mShuttle.setPenColor(screen, WHITE, 1.0f);
    //mShuttle.draw(screen, mShuttlePosition.x(), mShuttlePosition.y(),
    //               mShuttleOrientation, mShuttleSize);

    mGravityManager.body().polygon().setBrushColor(VESSEL, 1.0f);
    mGravityManager.body().polygon().setPenColor(WHITE, 1.0f);
    mGravityManager.body().polygon().draw(screen, mShuttlePosition.x(), mShuttlePosition.y(),
        mShuttleOrientation, mShuttleSize);


}

/*

CRÉÉER UNE CLASSE SHUTTLE QUI VA DESSINER UN VAISSEAU
" " " " " " " " " ASTEROID
*/