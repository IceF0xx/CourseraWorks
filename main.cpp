#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

#include "Testing Framework.h"
#include "Class Rational.h"

void Test1()
{
    AssertEqual(2,1+1,"1");
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