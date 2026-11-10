#include "figure.h"

int Figure::counter = 0;

Figure::Figure() {
    ++counter;
    fileName = std::to_string(counter);
}

Figure::~Figure() = default;