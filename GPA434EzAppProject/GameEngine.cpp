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
    mShuttleOrientation{},
    mAsteroidOrientation{},
    mShuttleSize{ 2.0f },
    mAsteroidSize{ 2.0f }
{
    mShuttle.buildVessel();
    mAsteroid.buildAsteroid();
}
*/

GameEngine::GameEngine()
    : mBodyInsertionTrigger{}
    , mBody(1)
{
    mGravityManager.setShapeOrigin(Vect2D(1200.0f / 2.0f, 1000.0f / 2.0f));

    for (int i{}; i < mBody.size(); ++i) {
        mBody[i].randomize(0.0f, 1200.0f, 0.0f, 1000.0f, 250.0f, 5.0f, 25.0f);
    }
}

GameEngine::~GameEngine()
{
}

bool GameEngine::processEvents(ezapp::Keyboard const& keyboard, ezapp::Timer const& timer) {
    // Cette partie sera remplacée par des fonctions de Body.h qui incluent les physiques
    double accelerate{ keyboard.isKeyPressed(ezapp::Keyboard::Key::Space) ? 10.0 : 1.0 };
    mTime += timer.secondSinceLastTic() * accelerate;
    mShuttlePosition.set(mTime * 50.0f, 450.0f);
    mAsteroidPosition.set(mTime * 50.0f, 225.0f);
    mShuttleOrientation = mTime;
    mAsteroidOrientation = mTime / 2;

    // run until ESCAPE is pressed
    return !keyboard.isKeyPressed(ezapp::Keyboard::Key::Escape);
}

void GameEngine::processDisplay(ezapp::Screen& screen) {
    //What is this mess?
    //c'est la couleur de quel objet qui est définie? De l'écran?? Du polygone?
    Color myColor(0x007300, 1.0f);
    Vect2D t1(1.0, 5.0), t2;        //C'est quoi ce vecteur??
    t1.normalize();

    double phaseR{ sin(mTime * 3.1415) * 0.5 + 0.5 };
    double phaseB{ cos(mTime * 3.1415) * 0.5 + 0.5 };
    myColor.setRed(phaseR);
    myColor.setBlue(phaseB);


    // Define background opaque medium dark blue grey color and apply it
    myColor.setBrush(screen);
    screen.clear();                             // apply color all over the screen

    // ...
   
    ShapeColors screenColor;
    screenColor.setBrushColor(screen, YELLOW, 1.0f);
    screenColor.setPenColor(screen, BORDER, 1.0f);
 //   fillColor.setBrush(screen);
 //   outlineColor.setPen(screen, );
    
    //mShuttle.setBrushColor(screen, VESSEL, 1.0f);
    //mShuttle.setPenColor(screen, WHITE, 1.0f);
    //mShuttle.draw(screen, mShuttlePosition.x(), mShuttlePosition.y(),
    //               mShuttleOrientation, mShuttleSize);

    mAsteroid.setBrushColor(screen, WHITE, 1.0f);
    mAsteroid.setPenColor(screen, WHITE, 1.0f);
    mAsteroid.draw(screen, mShuttlePosition.x(), mShuttlePosition.y(),
        mShuttleOrientation, mShuttleSize);


}

