#ifndef SHPERA_H
#define SPHERA_H

class Decart;

class Sphera
{
public:
    double lon, lat, R;
    Sphera();
    Sphera(double _lon, double _lat, double _R);
    operator Decart();
};

#endif // SPHERA_H