#ifndef RECORD_H
#define RECORD_H

#include <string>

struct Record
{
    long index = 0; // 1. record number
    int vesselId = 0; // 2. vessel ID
    double latitude = 0.0; // 3. geographic latitude
    double longitude = 0.0; // 4. geographic longitude
    int speedRaw = 0; // 5. speed in knots * 10
    int course = 0; // 6. course in degrees [0..359]
    int ageMinutes = 0; // 7. data age in minutes
    std::string dateTime; // 8. date and time of reception

    double speedKnots() const { return speedRaw / 10.0; }
};

#endif // RECORD_H