#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <set>

using namespace std;


class Rational {
public:
    Rational();

    Rational(int numerator, int denominator);

    int Numerator() const;

    int Denominator() const;

private:
    int up;
    int down;
    int NOD(int a, int b);
};

bool operator==(const Rational& rhs, const Rational& lhs);

bool operator!=(const Rational& rhs, const Rational& lhs);

Rational operator+(const Rational& rhs, const Rational& lhs);

Rational operator-(const Rational& rhs, const Rational& lhs);

Rational operator*(const Rational& rhs, const Rational& lhs);

Rational operator/(const Rational& rhs, const Rational& lhs);

ostream& operator<<(ostream& stream, const Rational& rhs);

istream& operator>>(istream& stream, Rational& rhs);

bool operator>(const Rational& rhs, const Rational& lhs);

bool operator<(const Rational& rhs, const Rational& lhs);