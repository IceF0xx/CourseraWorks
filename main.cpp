#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;

#include "Testing Framework.h"
#include "Class Rational.h"

void Test1()
{
    AssertEqual(2,sqrt(15),"2");
}
void TestAll()
{
    TestRunner tr;
    tr.RunTest(Test1,"T1");
}

int main()
{
    ios::sync_with_stdio(false);
    TestAll();
}