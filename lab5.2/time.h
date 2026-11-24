#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time();
    Time(int h, int m, int s);

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    long totalSeconds() const;

    bool operator<(const Time& other) const;
    bool operator==(const Time& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Time& t);
    friend std::istream& operator>>(std::istream& is, Time& t);
};

#endif // TIME_H