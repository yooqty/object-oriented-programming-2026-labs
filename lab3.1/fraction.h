#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class Fraction
{
public:
    int numerator;
    int denominator;
    Fraction();
    Fraction(int num, int den);
    Fraction operator+(Fraction f2);

    double toDouble() const;
    void normalize();
	
	Fraction operator+(Fraction f2) const;
    Fraction operator-(Fraction f2) const;
    Fraction operator*(Fraction f2) const;
    Fraction operator/(Fraction f2) const;

    Fraction operator+(int n) const;
    Fraction operator-(int n) const;
    Fraction operator*(int n) const;
    Fraction operator/(int n) const;
};

Fraction operator+(int n, const Fraction& f);
Fraction operator-(int n, const Fraction& f);
Fraction operator*(int n, const Fraction& f);
Fraction operator/(int n, const Fraction& f);

std::ostream& operator<<(std::ostream& os, const Fraction& f);

#endif // FRACTION_H
