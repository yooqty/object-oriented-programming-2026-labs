#include "mytime.h"
#include <iostream>

MyTime::MyTime() {
	hour = 0; min = 0; sec = 0;
}

MyTime::MyTime(int _hour, int _min, int _sec) {
	hour = _hour; min = _min; sec = _sec;
}

void MyTime::info() {
	std::cout << hour << ":" << min << ":" << sec << "\n";
}

MyTime MyTime::add(int sec) {
	this->sec = this->sec + sec;
	return *this;
}

MyTime MyTime::add(MyTime time) {
	hour = hour + time.hour;
	min = min + time.min;
	sec = sec + time.sec;
	return *this;
}
