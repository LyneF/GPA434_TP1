#pragma once
#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include "Shuttle.h"
#include <vector>
#include <ezapp>

class GameEngine
{
private:
	Shuttle mShuttle{ };
	vector mAsteroid;
	vector mMissiles;

public:
	bool provessEvents(const ezapp::Keyboard& keyboard, const ezapp::Timer& timer);
	void processDispaly(ezapp::Screen &screen);



};

