#pragma once



class Random
{
public:
	Random() = delete;
	~Random() = delete;
	Random& operator=(Random const & rhs) = delete;
	Random(Random const & random) = delete;

	static int integer(int from, int to);
	static float real();
	static float real(int from, int to);

};

