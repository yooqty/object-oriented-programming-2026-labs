#include "time.h"

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

int Time::getHours() const { return hours; }
int Time::getMinutes() const { return minutes; }
int Time::getSeconds() const { return seconds; }

long Time::totalSeconds() const {
    return hours * 3600L + minutes * 60L + seconds;
}

bool Time::operator<(const Time& other) const {
    return totalSeconds() < other.totalSeconds();
}

bool Time::operator==(const Time& other) const {
    return totalSeconds() == other.totalSeconds();
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
    // format HH:MM:SS with leading zeros
    os << (t.hours < 10 ? "0" : "") << t.hours << ":"
       << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
       << (t.seconds < 10 ? "0" : "") << t.seconds;
    return os;
}

std::istream& operator>>(std::istream& is, Time& t) {
    char c1, c2;
    is >> t.hours >> c1 >> t.minutes >> c2 >> t.seconds;
    return is;
}