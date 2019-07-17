#include "testing_framework.h"
TestRunner::~TestRunner()
{

    if (fail_count > 0) {
        cerr << success_count << '/' << success_count + fail_count << (success_count + fail_count > 1 ? " tests" : " test")
        << " completed successfully" << (success_count + fail_count > 1 ? "  |" : "   |") << endl;
        for (int i = 0; i < 34; ++i){
            cerr << '-';
        }
        cerr << '+' << endl;
        exit(127);
    }
    for (int i = 0; i < 34; ++i){
        cerr << '-';
    }
    cerr << '+' << endl;
    cerr << "All the tests successfully passed |" << endl;
    for (int i = 0; i < 34; ++i){
        cerr << '-';
    }
    cerr << '+' << endl;
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}