#pragma once


//Classe permettant de 
class Random
{
public:
	Random() = delete;
	~Random() = default;
	Random& operator=(Random const & rhs) = delete;
	Random(Random const & random) = delete;

	static int integer(int from, int to);
	static float real();
	static float real(int from, int to);

};

