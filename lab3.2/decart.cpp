#include "decart.h"
#include "sphera.h"
#include <math.h>

Decart::Decart()
{
    x = 0; y = 0; z = 0;
}

Decart::Decart(double _x, double _y, double _z)
{
    x = _x; y = _y; z = _z;
}

// conversion operator: cartesian -> spherical
Decart::operator Sphera()
{
    Sphera result;
    result.R = sqrt(x*x + y*y + z*z);
    result.lon = atan2(y,x);
    result.lat = asin(z/result.R);
    return result;
}

// euclidean distance
double Decart::euclideanDistance(const Decart& p1, const Decart& p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// print
std::ostream& operator<<(std::ostream& os, const Decart& p)
{
    os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return os;
}