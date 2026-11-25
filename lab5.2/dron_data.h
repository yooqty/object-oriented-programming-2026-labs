#ifndef DRON_DATA_H
#define DRON_DATA_H

#include <iostream>
#include "time.h"

class DronData {
private:
    Time time;
    int temperature; // degrees
    double depth; // meters

public:
    DronData();
    DronData(const Time& t, int temp, double d);

    Time getTime() const;
    int getTemperature() const;
    double getDepth() const;

    bool operator<(DronData data) const;

    friend std::ostream& operator<<(std::ostream& os, const DronData& d);
    friend std::istream& operator>>(std::istream& is, DronData& d);
};

#endif // DRON_DATA_H
