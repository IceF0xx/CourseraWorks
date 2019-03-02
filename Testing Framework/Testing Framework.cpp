#pragma once

#include "Testing Framework.h"
TestRunner::~TestRunner()
{
    if (fail_count > 0) {
        cerr << "In UNIT-test " << (fail_count > 1 ? "were" : "was") << " found " << fail_count << (fail_count > 1 ? " errors" : " error") << endl;
        exit(1);
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}