#pragma once

#include "Class Rational.h"
bool operator==(const Rational& rhs, const Rational& lhs)
{
    return rhs.Numerator() * lhs.Denominator() == lhs.Numerator() * rhs.Denominator();
}


bool operator!=(const Rational& rhs, const Rational& lhs)
{
    return rhs.Numerator() * lhs.Denominator() != lhs.Numerator() * rhs.Denominator();
}

Rational operator+(const Rational& rhs, const Rational& lhs)
{
    return {rhs.Numerator() * lhs.Denominator() + rhs. Denominator() * lhs. Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator-(const Rational& rhs, const Rational& lhs)
{
    return {rhs.Numerator() * lhs.Denominator() - rhs. Denominator() * lhs. Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator*(const Rational& rhs, const Rational& lhs)
{
    return {rhs.Numerator() * lhs. Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator/(const Rational& rhs, const Rational& lhs)
{
    return {rhs.Numerator() * lhs.Denominator(), rhs.Denominator() * lhs.Numerator()};
}

ostream& operator<<(ostream& stream, const Rational& rhs)
{
    stream << rhs.Numerator() << "/" << rhs.Denominator();
    return stream;
}
istream& operator>>(istream& stream, Rational& rhs)
{
    int p = 0, q = 0;
    if (stream >> p && stream.ignore(1) && stream >> q)
    {
        rhs = { p, q };
    }
    return stream;
}

bool operator>(const Rational& rhs, const Rational& lhs)
{
    return rhs.Numerator() * lhs.Denominator() > lhs.Numerator() * rhs.Denominator();
}

bool operator<(const Rational& rhs, const Rational& lhs)
{
    return rhs.Numerator() * lhs.Denominator() < lhs.Numerator() * rhs.Denominator();
}
