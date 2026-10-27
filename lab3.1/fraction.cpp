#include "fraction.h"
#include <cmath>
#include <stdexcept>

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int num, int den)
{
    if (den == 0)
        throw std::invalid_argument("Denominator cannot be zero");
    numerator = num;
    denominator = den;
}

Fraction Fraction::operator+(Fraction f2)
{
    Fraction result;
    result.numerator = numerator * f2.denominator + f2.numerator * denominator;
    result.denominator = denominator * f2.denominator;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
    os << f.numerator << "/" << f.denominator;
    return os;
}

// ================= Added code =================

double Fraction::toDouble() const
{
    return static_cast<double>(numerator) / denominator;
}

void Fraction::normalize()
{
    if (denominator == 0) return;
    if (denominator < 0) { numerator = -numerator; denominator = -denominator; }
    int a = std::abs(numerator);
    int b = std::abs(denominator);
    while (b) { int t = a % b; a = b; b = t; }
    int g = (a == 0) ? 1 : a;
    numerator   /= g;
    denominator /= g;
}

Fraction Fraction::operator-(Fraction f2) const
{
    return Fraction(numerator * f2.denominator - f2.numerator * denominator,
                    denominator * f2.denominator);
}

Fraction Fraction::operator*(Fraction f2) const
{
    return Fraction(numerator * f2.numerator, denominator * f2.denominator);
}

Fraction Fraction::operator/(Fraction f2) const
{
    if (f2.numerator == 0)
        throw std::invalid_argument("Division by zero fraction");
    return Fraction(numerator * f2.denominator, denominator * f2.numerator);
}

// Fraction op int
Fraction Fraction::operator+(int n) const 
{ 
    Fraction result(numerator + n * denominator, denominator);
    result.normalize();
    return result; 
}

Fraction Fraction::operator-(int n) const 
{ 
    Fraction result(numerator - n * denominator, denominator);
    result.normalize();
    return result; 
}

Fraction Fraction::operator*(int n) const 
{ 
    return *this * Fraction(n, 1); 
}

Fraction Fraction::operator/(int n) const 
{ 
    return *this / Fraction(n, 1); 
}

// int op Fraction
Fraction operator+(int n, const Fraction& f) 
{ 
    Fraction result(n * f.denominator + f.numerator, f.denominator);
    result.normalize();
    return result; 
}

Fraction operator-(int n, const Fraction& f) 
{ 
    Fraction result(n * f.denominator - f.numerator, f.denominator);
    result.normalize();
    return result; 
}

Fraction operator*(int n, const Fraction& f) 
{ 
    return Fraction(n * f.numerator, f.denominator); 
}

Fraction operator/(int n, const Fraction& f) 
{ 
    return Fraction(n * f.denominator, f.numerator); 
}