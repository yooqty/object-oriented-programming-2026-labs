#pragma once
#include "figure.h"

class Rectangle : public Figure {
private:
    int x1, y1; // bottom-left vertex
    int x2, y2; // top-right vertex

public:
    Rectangle(); // default constructor
    Rectangle(int x1, int y1, int x2, int y2); // parameterized constructor
    Rectangle(const Rectangle& other); // copy constructor
    Rectangle& operator=(const Rectangle& other); // assignment operator
    ~Rectangle() override; // destructor

    void loadFromFile() override;
    void saveToFile() const override;
    std::string toString() override;

    // coordinate accessors
    int getX1() const { return x1; }
    int getY1() const { return y1; }
    int getX2() const { return x2; }
    int getY2() const { return y2; }
    void setCoords(int a, int b, int c, int d) { x1 = a; y1 = b; x2 = c; y2 = d; }
};