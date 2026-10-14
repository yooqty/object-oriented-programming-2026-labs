#include "mytime.h"
#include <iostream>
#include <iomanip>

MyTime::MyTime() {
	hour = 0; min = 0; sec = 0;
}

MyTime::MyTime(int _hour, int _min, int _sec) {
	hour = _hour; min = _min; sec = _sec;
	normalize();
}

// Bring the time to a "normal" form: 0..23 h, 0..59 min, 0..59 sec
void MyTime::normalize() {
    int total = toSeconds();
    // Reduce to the 24-hour range
    total = ((total % 86400) + 86400) % 86400;
    hour = total / 3600;
    min  = (total % 3600) / 60;
    sec  = total % 60;
}

void MyTime::info() {
    // Print with leading zeros, e.g. 05:02:09
    std::cout << std::setfill('0') << std::setw(2) << hour << ":"
              << std::setfill('0') << std::setw(2) << min  << ":"
              << std::setfill('0') << std::setw(2) << sec  << "\n";
}

MyTime MyTime::add(int sec) {
	this->sec = this->sec + sec;
	normalize();
	return *this;
}

MyTime MyTime::sub(int sec) {
    this->sec = this->sec - sec;
    normalize();
    return *this;
}

MyTime MyTime::add(MyTime time) {
	hour = hour + time.hour;
	min = min + time.min;
	sec = sec + time.sec;
	normalize();
	return *this;
}

MyTime MyTime::sub(MyTime time) {
    hour = hour - time.hour;
    min  = min  - time.min;
    sec  = sec  - time.sec;
    normalize();
    return *this;
}

int MyTime::toSeconds() const {
    return hour * 3600 + min * 60 + sec;
}

bool MyTime::operator<(const MyTime& other) const {
    return toSeconds() < other.toSeconds();
}
bool MyTime::operator>(const MyTime& other) const {
    return toSeconds() > other.toSeconds();
}
bool MyTime::operator<=(const MyTime& other) const {
    return toSeconds() <= other.toSeconds();
}
bool MyTime::operator>=(const MyTime& other) const {
    return toSeconds() >= other.toSeconds();
}
