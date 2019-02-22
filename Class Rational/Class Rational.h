#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

class Rational {
public:
    Rational() {
        up = 0;
        down = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator < 0)
        {
            up = - numerator / NOD(numerator,denominator);
            down = abs(denominator) / NOD(numerator,denominator);
            return;
        }
        up = numerator / NOD(numerator,denominator);
        down = denominator / NOD(numerator,denominator);
    }

    int Numerator() const {
        return  up;
    }

    int Denominator() const {
        return down;
    }

private:
    int up;
    int down;

    int NOD(int a, int b)
    {
        a = abs(a);
        b = abs(b);
        while (b) {
            a %= b;
            swap (a, b);
        }
        return a;
    };

};
