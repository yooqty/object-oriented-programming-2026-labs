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

Decart::operator Sphera()
{
    Sphera result;
    result.R = sqrt(x*x + y*y + z*z);
    result.lon = atan2(y,x);
    result.lat = asin(z/result.R);
    return result;
}