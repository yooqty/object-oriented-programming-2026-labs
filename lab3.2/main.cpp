#include <iostream>
#include "decart.h"
#include "sphera.h"

int main()
{
    Decart d1, d2(3,4,5);
    Sphera s1, s2(0.5, 1, 10);

    d1 = s2;
    std::cout << d1.x << ", " << d1.y << ", " << d1.z << "\n";
    s1 = d2;
    std::cout << s1.lon << ", " << s1.lat << ", " <<s1.R << "\n";

    return 0;
}