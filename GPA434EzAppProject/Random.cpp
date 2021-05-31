#include "Random.h"


#include <random>



int Random::integer(int from, int to)
{
    return rand() % (to - from) + from;
}

float Random::real()
{
    return (float)rand() / RAND_MAX;
}

float Random::real(int from, int to)
{
    return real() * (to - from) + from;
}
