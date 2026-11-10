#ifndef BIRTHDATE_H
#define BIRTHDATE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>

class BirthDate
{
public:
    int day;
    int month;
    int year;

    BirthDate();
    BirthDate(int d, int m, int y);
    BirthDate(const std::string& str); // "dd.mm.yyyy"

    bool operator<(const BirthDate& other) const;
    bool operator>(const BirthDate& other) const;
    bool operator==(const BirthDate& other) const;
    bool operator<=(const BirthDate& other) const;
    bool operator>=(const BirthDate& other) const;

    BirthDate operator+(const BirthDate& other) const;
    BirthDate operator/(int n) const;

    // difference between dates (in days)
    int operator-(const BirthDate& other) const;

    friend std::ostream& operator<<(std::ostream& os, const BirthDate& d);

    static int toDays(const BirthDate& d);
};

#endif // BIRTHDATE_H