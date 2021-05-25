#include "GameEngine.h"

GameEngine::GameEngine()
    :mPentagon(),
    mFillColor(1.0f, 1.0f, 0.0f, 1.0f),
    mOutlineColor(1.0f, 0.5f, 0.0f, 1.0f),
    mPentagonPosition(0.0f, 450.0f),
    mPentagonOrientation{},
    mPentagonSize{ 2.0f }
{
   // mPentagon.buildCircle(20.0f, 30);
  //  mPentagon.buildRectangle(30.0f, 10);
   // mPentagon.buildTriangle(20.0f, 30);
    mPentagon.buildVessel(30.0f, 15.0f, 20.0f, 30);
}

GameEngine::~GameEngine()
{

}

bool GameEngine::processEvents(ezapp::Keyboard const& keyboard, ezapp::Timer const& timer) {
    // ...
    double accelerate{ keyboard.isKeyPressed(ezapp::Keyboard::Key::Space) ? 10.0 : 1.0 };
    mTime += timer.secondSinceLastTic() * accelerate;
    mPentagonPosition.set(mTime * 50.0f, 450.0f);
    mPentagonOrientation = mTime;

    // run until ESCAPE is pressed
    return !keyboard.isKeyPressed(ezapp::Keyboard::Key::Escape);
}

void GameEngine::processDisplay(ezapp::Screen& screen) {
    Color myColor(0.0f, 0.45f, 0.0f, 1.0f);
    Vect2D t1(1.0, 5.0), t2;
    t1.normalize();

    double phaseR{ sin(mTime * 3.1415) * 0.5 + 0.5 };
    double phaseB{ cos(mTime * 3.1415) * 0.5 + 0.5 };
    myColor.setRed(phaseR);
    myColor.setBlue(phaseB);


    // Define background color and apply it
    //screen.setBrush(myColor.red(), myColor.green(), myColor.blue(), myColor.alpha()); // opaque medium dark blue grey
    myColor.setBrush(screen);
    screen.clear();                             // apply color all over the screen

    // ...
   
    Color fillColor(1.0f, 1.0f, 0.0f, 1.0f);
    Color outlineColor(1.0f, 0.5f, 0.0f, 1.0f);
    fillColor.setBrush(screen);
    outlineColor.setPen(screen);

    mPentagon.draw(screen, mPentagonPosition.x(), mPentagonPosition.y(), mPentagonOrientation, mPentagonSize);

}

