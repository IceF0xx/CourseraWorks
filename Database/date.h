#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Date {
public:
    Date();
    Date(const int& year,const int& month, const int& day);

    const vector<int16_t>& DateVal() const;

    const string DateStr() const;

private:
    const vector<int16_t> date_;
};

const bool operator <(const Date& lhs, const Date& rhs);

ostream& operator <<(ostream& os, const Date& date);

Date ParseDate(istream& is);