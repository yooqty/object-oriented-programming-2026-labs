#pragma once
#include "figure.h"

class Triangle : public Figure {
private:
    int x1, y1;
    int x2, y2;
    int x3, y3;

public:
    Triangle();
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);
    ~Triangle() override;

    void loadFromFile() override;
    void saveToFile() const override;
    std::string toString() override;

    void setCoords(int a, int b, int c, int d, int e, int f) {
        x1=a; y1=b; x2=c; y2=d; x3=e; y3=f;
    }
};