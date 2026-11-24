#include "dron_data.h"

DronData::DronData() : time(), temperature(0), depth(0.0) {}

DronData::DronData(const Time& t, int temp, double d)
    : time(t), temperature(temp), depth(d) {}

Time DronData::getTime() const { return time; }
int DronData::getTemperature() const { return temperature; }
double DronData::getDepth() const { return depth; }

// 1) sort by depth
bool DronData::operator<(DronData data) const {
    return depth < data.depth;
}

// 2) sort by temperature
//bool DronData::operator<(DronData data) const {
//    return temperature < data.temperature;
//}

// 3) sort by time
//bool DronData::operator<(DronData data) const {
//    return time < data.time;
//}

std::ostream& operator<<(std::ostream& os, const DronData& d) {
    os << "[" << d.time << "] T=" << d.temperature
       << " C, depth=" << d.depth << " m";
    return os;
}

std::istream& operator>>(std::istream& is, DronData& d) {
    is >> d.time >> d.temperature >> d.depth;
    return is;
}