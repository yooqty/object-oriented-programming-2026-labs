#include "sphera.h"
#include "decart.h"
#include <math.h>

Sphera::Sphera()
{
    lon = 0; lat = 0; R = 0;
}

Sphera::Sphera(double _lon, double _lat, double _R)
{
    lon = _lon; lat = _lat; R = _R;
}

// conversion operator: spherical -> cartesian
Sphera::operator Decart()
{
    Decart result;
    result.x = R * cos(lat) * cos(lon);
    result.y = R * cos(lat) * sin(lon);
    result.z = R * sin(lat);
    return result;
}

// great-circle distance
double Sphera::bigCircleDistance(const Sphera& p1, const Sphera& p2)
{
    const double Rearth = 6371000.0;
    const double PI = 3.14159265358979323846;

    double lat1 = p1.lat * PI / 180.0;
    double lon1 = p1.lon * PI / 180.0;
    double lat2 = p2.lat * PI / 180.0;
    double lon2 = p2.lon * PI / 180.0;

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlat/2)*sin(dlat/2)
             + cos(lat1)*cos(lat2)*sin(dlon/2)*sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return Rearth * c;
}

// print
std::ostream& operator<<(std::ostream& os, const Sphera& p)
{
    os << "(lon=" << p.lon << ", lat=" << p.lat << ", R=" << p.R << ")";
    return os;
}