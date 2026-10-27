#ifndef DECART_H
#define DECART_H

#include <iostream>

class Sphera;

class Decart
{
public:
    double x, y, z;
    Decart();
    Decart(double _x, double _y, double _z);
    operator Sphera();

    static double euclideanDistance(const Decart& p1, const Decart& p2);
};

std::ostream& operator<<(std::ostream& os, const Decart& p);

#endif // DECART_H