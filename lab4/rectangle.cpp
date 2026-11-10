#include "rectangle.h"
#include <fstream>
#include <sstream>
#include <iostream>

Rectangle::Rectangle() : Figure(), x1(0), y1(0), x2(1), y2(1) {
    fileName += " Rectangle";
    saveToFile();
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
    : Figure(), x1(x1), y1(y1), x2(x2), y2(y2) {
    fileName += " Rectangle";
    saveToFile();
}

// copy constructor: new object -> new file, copy of coordinates
Rectangle::Rectangle(const Rectangle& other) : Figure() {
    fileName += " Rectangle";
    const_cast<Rectangle&>(other).loadFromFile();
    x1 = other.x1; y1 = other.y1; x2 = other.x2; y2 = other.y2;
    saveToFile();
}

// assignment operator: copies only coordinates
Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        const_cast<Rectangle&>(other).loadFromFile();
        x1 = other.x1; y1 = other.y1; x2 = other.x2; y2 = other.y2;
        saveToFile();
    }
    return *this;
}

Rectangle::~Rectangle() {
    std::remove(fileName.c_str());
}

void Rectangle::loadFromFile() {
    std::ifstream in(fileName);
    if (!in.is_open()) return;
    in >> x1 >> y1 >> x2 >> y2;
    in.close();
}

void Rectangle::saveToFile() const {
    std::ofstream out(fileName);
    out << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
    out.close();
}

std::string Rectangle::toString() {
    loadFromFile();
    std::ostringstream os;
    os << "Rectangle [" << fileName << "]: ("
       << x1 << ", " << y1 << ") - ("
       << x2 << ", " << y2 << ")";
    return os.str();
}