#pragma once
#ifndef _BODY_H_
#define _BODY_H_
// #include

class Body
{
private:
	ezapp::Physics mPhysics{ };
	ezapp::Polygon mShape{ };

public:
	void reset();
	void applyLinearAcceleration(Vect2D acceleration);
	void 



};