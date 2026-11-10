#include "birthdate.h"

BirthDate::BirthDate() : day(1), month(1), year(2000) {}

BirthDate::BirthDate(int d, int m, int y) : day(d), month(m), year(y) {}

BirthDate::BirthDate(const std::string& str)
{
    char dot1, dot2;
    std::istringstream iss(str);
    if (!(iss >> day >> dot1 >> month >> dot2 >> year) || dot1 != '.' || dot2 != '.')
        throw std::invalid_argument("Bad date format: " + str);
}

bool BirthDate::operator<(const BirthDate& other) const
{
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool BirthDate::operator>(const BirthDate& other) const { return other < *this; }
bool BirthDate::operator==(const BirthDate& other) const
{
    return year == other.year && month == other.month && day == other.day;
}
bool BirthDate::operator<=(const BirthDate& other) const { return !(other < *this); }
bool BirthDate::operator>=(const BirthDate& other) const { return !(*this < other); }

// for average: convert to days, average, convert back to date
BirthDate BirthDate::operator+(const BirthDate& other) const
{
    int total = toDays(*this) + toDays(other);
    // simplified reverse conversion: build the "average" date by year
    int days = total / 2;
    int y = 2000;
    while (true) {
        int daysInYear = ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 366 : 365;
        if (days < daysInYear) break;
        days -= daysInYear;
        y++;
    }
    static const int mdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int m = 1;
    while (true) {
        int dim = mdays[m-1];
        if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)) dim = 29;
        if (days < dim) break;
        days -= dim;
        m++;
    }
    return BirthDate(days + 1, m, y);
}

BirthDate BirthDate::operator/(int n) const
{
    BirthDate zero(1, 1, 2000);
    int total = toDays(*this) + toDays(zero) * (n - 1);
    return BirthDate(1,1,2000) + BirthDate(1,1,2000);
}

int BirthDate::operator-(const BirthDate& other) const
{
    return toDays(*this) - toDays(other);
}

int BirthDate::toDays(const BirthDate& d)
{
    int days = 0;
    for (int y = 2000; y < d.year; y++)
        days += ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 366 : 365;
    static const int mdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for (int m = 1; m < d.month; m++) {
        int dim = mdays[m-1];
        if (m == 2 && ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)) dim = 29;
        days += dim;
    }
    days += d.day - 1;
    return days;
}

std::ostream& operator<<(std::ostream& os, const BirthDate& d)
{
    os << std::setw(2) << std::setfill('0') << d.day << "."
       << std::setw(2) << std::setfill('0') << d.month << "."
       << d.year;
    return os;
}