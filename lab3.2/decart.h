#ifndef DECART_H
#define DECART_H

class Sphera;

class Decart
{
public:
    double x,y,z;
    Decart();
    Decart(double _x, double _y, double _z);
    operator Sphera();
};

#endif // DECART_H