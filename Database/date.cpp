#include "date.h"

#include <iomanip>

Date :: Date(const int& year, const int& month, const int& day)
        : date_({static_cast<int16_t>(year),
                 static_cast<int16_t>(month),
                 static_cast<int16_t>(day)}) {
}

const vector<int16_t>& Date::DateVal() const {
    return date_;
}

const string Date::DateStr() const {
    stringstream os;
    auto it = date_.begin();
    os << setfill('0') << setw(4) << *it << '-'
       << setw(2) << *(++it) << '-'
       << setw(2) << *(++it);
    return os.str();
}

const bool operator <(const Date& lhs, const Date& rhs) {
    return (lhs.DateVal() < rhs.DateVal());
}

ostream& operator <<(ostream& os, const Date& date) {
    return os << date.DateStr();
}

Date ParseDate(istream& is) {
    int year, month, day;
    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;
    return Date(year, month, day);
}