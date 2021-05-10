#pragma once
#ifndef _ATEROID_H_
#define _ASTEROID_H_

// #include

class asteroid
{
private:
	ezapp::Body mBody{ };
	

public:
	float processTime(float elapsedTime);
	void drawOnScreen(Screen &screen);




};

