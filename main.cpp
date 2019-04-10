#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "Class Rational/Class Rational.h"
#include "Testing Framework/Testing Framework.h"


using namespace std;


void test_1(){
    Rational r1 {2,10};
    AssertEqual(1, r1.Numerator(), "test_1");
    AssertEqual(5, r1.Denominator(), "test_2");
}


int main(){
    TestRunner tr;
    RUN_TEST(tr, test_1);
}
