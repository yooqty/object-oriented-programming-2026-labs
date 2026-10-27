#include <iostream>
#include "fraction.h"
#include <stdexcept>

using namespace std;

int main()
{
    Fraction f1, f2(1,2), f3(2,3);
    cout << f1 << ", " << f2 << ", " << f3 << "\n";
    f1 = f2 + f3;
    cout << f1 << "\n";

    // ================= Added code =================

    cout << "\n--- toDouble / normalize ---\n";
    Fraction a(4, 8);
    cout << "Before: " << a << "  double=" << a.toDouble() << "\n";
    a.normalize();
    cout << "After : " << a << "  double=" << a.toDouble() << "\n";

    cout << "\n--- Arithmetic (fraction op fraction) ---\n";
    Fraction x(1, 2), y(1, 3);
    cout << x << " + " << y << " = " << (x + y) << "\n"; 
    cout << x << " - " << y << " = " << (x - y) << "\n";
    cout << x << " * " << y << " = " << (x * y) << "\n";
    cout << x << " / " << y << " = " << (x / y) << "\n";

    cout << "\n--- Arithmetic (fraction op int / int op fraction) ---\n";
    cout << x << " + 2 = " << (x + 2) << "\n";
    cout << "2 + " << x << " = " << (2 + x) << "\n";
    cout << x << " * 3 = " << (x * 3) << "\n";
    cout << "3 * " << x << " = " << (3 * x) << "\n";
    cout << x << " - 1 = " << (x - 1) << "\n";
    cout << "1 - " << x << " = " << (1 - x) << "\n";
    cout << x << " / 2 = " << (x / 2) << "\n";
    cout << "2 / " << x << " = " << (2 / x) << "\n";

    cout << "\n--- Denominator check ---\n";
    try {
        Fraction bad(1, 0);
        cout << "No exception: " << bad << "\n";
    } catch (const std::exception& e) {
        cout << "Exception caught: " << e.what() << "\n";
    }

    cout << "\n--- 2x2 Matrix of Fractions: Square and Determinant ---\n";
    Fraction A[2][2] = { {Fraction(1,2), Fraction(1,3)},
                         {Fraction(1,4), Fraction(1,5)} };

    cout << "A = [ " << A[0][0] << "  " << A[0][1] << " ]\n";
    cout << "    [ " << A[1][0] << "  " << A[1][1] << " ]\n";

    // Determinant det = a*d - b*c
    Fraction det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    det.normalize();
    cout << "det(A) = " << det << "  (double = " << det.toDouble() << ")\n";

    // A^2
    Fraction A2[2][2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            A2[i][j] = A[i][0] * A[0][j] + A[i][1] * A[1][j];
            A2[i][j].normalize();
        }
    }

    cout << "\nA^2 =\n";
    cout << "    [ " << A2[0][0] << "  " << A2[0][1] << " ]\n";
    cout << "    [ " << A2[1][0] << "  " << A2[1][1] << " ]\n";

    return 0;
}