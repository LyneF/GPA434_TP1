#pragma once
#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_
// #include

class GameEngine
{
private:
	ezapp::Shuttle mShuttle{ };
	vector mAsteroid;
	vector mMissiles;

public:
	bool provessEvents(const Keyboard& keyboard, const Timer& timer);
	void processDispaly(Screen &screen);



};

