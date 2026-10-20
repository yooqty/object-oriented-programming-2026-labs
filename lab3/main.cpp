#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
    Fraction f1, f2(1,2), f3(2,3);
    cout << f1 << ", " << f2 << ", " << f3 << "\n";
    f1 = f2 + f3;
    cout << f1 << "\n";

    return 0;
}