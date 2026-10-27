#ifndef SPHERA_H
#define SPHERA_H

#include <iostream>

class Decart;

class Sphera
{
public:
    double lon, lat, R;
    Sphera();
    Sphera(double _lon, double _lat, double _R);
    operator Decart();

    static double bigCircleDistance(const Sphera& p1, const Sphera& p2);
};

std::ostream& operator<<(std::ostream& os, const Sphera& p);

#endif // SPHERA_H