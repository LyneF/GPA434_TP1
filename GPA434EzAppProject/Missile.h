#pragma once
#ifndef _MISSILE_H
#define _MISSILE_H

// #include

class Missile
{
private:
	ezapp::Body mBody{ };
	float mFuelLevel{ },
		  mThrustPower{ };	


public:
	float processTime(float elapsedTime);
	void drawOnScreen(Screen& screen);
	bool isColliding(const Asteroid& asteroid);





};

