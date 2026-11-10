#include "triangle.h"
#include <fstream>
#include <sstream>
#include <cstdio>

Triangle::Triangle() : Figure(),
    x1(0), y1(0), x2(1), y2(0), x3(0), y3(1) {
    fileName += " Triangle";
    saveToFile();
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
    : Figure(), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
    fileName += " Triangle";
    saveToFile();
}

Triangle::Triangle(const Triangle& other) : Figure() {
    fileName += " Triangle";
    const_cast<Triangle&>(other).loadFromFile();
    x1=other.x1; y1=other.y1;
    x2=other.x2; y2=other.y2;
    x3=other.x3; y3=other.y3;
    saveToFile();
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        const_cast<Triangle&>(other).loadFromFile();
        x1=other.x1; y1=other.y1;
        x2=other.x2; y2=other.y2;
        x3=other.x3; y3=other.y3;
        saveToFile();
    }
    return *this;
}

Triangle::~Triangle() {
    std::remove(fileName.c_str());
}

void Triangle::loadFromFile() {
    std::ifstream in(fileName);
    if (!in.is_open()) return;
    in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    in.close();
}

void Triangle::saveToFile() const {
    std::ofstream out(fileName);
    out << x1 << ' ' << y1 << ' '
        << x2 << ' ' << y2 << ' '
        << x3 << ' ' << y3;
    out.close();
}

std::string Triangle::toString() {
    loadFromFile();
    std::ostringstream os;
    os << "Triangle [" << fileName << "]: ("
       << x1 << ", " << y1 << "), ("
       << x2 << ", " << y2 << "), ("
       << x3 << ", " << y3 << ")";
    return os.str();
}