#include "GravityManager.h"
#include "GravityManager.h"


#include <algorithm>


GravityManager::GravityManager()
    : mGravityStrength{ 100.0f }
    , mGravity()
{
    mShape.build7PointsArrow(0.0f, 0.0f, 250.0f, 250.0f, 0.5f, 0.5f);
    mShape.fillColor().setColor(0.5f, 0.5f, 1.0f);
    mShape.outlineColor().setColor(0.25f, 0.25f, 1.0f);
    mShape.setOutlineWidth(2.5f);
}

float GravityManager::gravityStrength() const
{
    return mGravityStrength;
}

Vect2D GravityManager::gravity() const
{
    return mGravity;
}

void GravityManager::setGravityStrength(float strength)
{
    mGravityStrength = std::clamp(strength, 1.0f, 10000.0f);
}

void GravityManager::setShapeOrigin(Vect2D const& shapeOrigin)
{
    mShapeOrigin = shapeOrigin;
}

void GravityManager::update(ezapp::Keyboard const& keyboard)
{
    mGravity.reset();
    if (keyboard.isKeyPressed(ezapp::Keyboard::Key::Up)) {
        mGravity += Vect2D(0.0f, -mGravityStrength);
    }
    if (keyboard.isKeyPressed(ezapp::Keyboard::Key::Down)) {
        mGravity += Vect2D(0.0f, mGravityStrength);
    }
    if (keyboard.isKeyPressed(ezapp::Keyboard::Key::Left)) {
        mGravity += Vect2D(-mGravityStrength, 0.0f);
    }
    if (keyboard.isKeyPressed(ezapp::Keyboard::Key::Right)) {
        mGravity += Vect2D(mGravityStrength, 0.0f);
    }
}

void GravityManager::draw(ezapp::Screen& screen)
{
    if (mGravity.isValid()) {
        mShape.draw(screen, mShapeOrigin.x(), mShapeOrigin.y(), mGravity.orientation() - 3.141592654f / 2.0f, 1.0f);
    }
}
