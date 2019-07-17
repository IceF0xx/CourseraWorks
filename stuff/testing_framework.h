#pragma once
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <future>
#include <vector>
#include "profile.h"
#include "outputs.h"

#define RUN_TEST(tr, func) \
    tr.RunTest(func, #func)

#define ASSERT_EQUAL(x, y) {                     \
    ostringstream very_imprtant_ss_that_nobody_will_use;                            \
    very_imprtant_ss_that_nobody_will_use << __FILE__ << ":" << __LINE__;           \
    AssertEqual(x, y, very_imprtant_ss_that_nobody_will_use.str());                 \
    }

#define ASSERT(x) {                               \
    ostringstream veru_imprtant_ss_that_nobody_will_use;                            \
    veru_imprtant_ss_that_nobody_will_use << __FILE__ << ":" << __LINE__;           \
    Assert(x, veru_imprtant_ss_that_nobody_will_use.str());                         \
    }

using namespace std;


template <typename Iterator>
class IteratorRange{
public:
    IteratorRange(Iterator F, Iterator L)
            : first(F),
              second(L) {}

    Iterator begin() const {
        return first;
    }

    Iterator end() const {
        return second;
    }

    size_t size() const{
        return distance(begin(), end());
    }
private:
    Iterator first;
    Iterator second;
};


template<class T, class U>
void AssertEqual(const T& t, const U& u,
                 const string& source);

template <typename Container>
auto Range(Container& v, size_t begin, size_t end);

template <typename Container>
auto Range(Container& v, size_t end);

void Assert(bool b, const string& hint);

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end);

class TestRunner {
public:
    template <typename TestFunc>
    void RunTest(TestFunc func, const string& test_name);
    ~TestRunner();
private:
    int fail_count = 0;
    int success_count = 0;
};

template <typename TestFunc>
void TestRunner::RunTest(TestFunc func, const string& test_name)
{
    try {
        func();
        ++success_count;
        cerr << test_name << " is good";
        for (int i = 0 ; i < 54 - test_name.size(); ++i){
            cerr << ' ';
        }
        cerr << '|' << endl;
        for (int i = 0; i < 62; ++i){
            cerr << '-';
        }
        cerr << '+' << endl;
    } catch (exception& e) {
        ++fail_count;
        cerr << test_name << " failed => " << e.what();
    }
}


template<class T, class U>
void AssertEqual(const T& t, const U& u,
                 const string& source)
{
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u << endl;
        os << "Source: " << source << "|" << endl;
        for (int i = 0; i < 8 + source.size(); ++i){
            os << '-';
        }
        os << '+' << endl;
        throw runtime_error(os.str());
    }
}

template <typename Container>
auto Range(Container& v, size_t end){
    end--;
    if (end < 0 || end >= v.size()){
        ostringstream os;
        os << endl << "invalid_argument: " << __FILE__ << ":" << __LINE__ - 3;
        throw out_of_range(os.str());
    }
    return IteratorRange{v.begin(), next(++v.begin(),
                         min(end, v.size()))};
}


template <typename Container>
auto Head(Container& c, int top) {
    return IteratorRange(begin(c), begin(c) + min<size_t>(max(top, 0), c.size()));
}

template <typename Container>
auto Range(Container& v, size_t begin, size_t end){
    if (begin > end || end < 0 || end >= v.size() || begin >= v.size() || begin < 0){
        ostringstream os;
        os << endl << "invalid_argument: " << __FILE__ << ':' << __LINE__ - 3;
        throw out_of_range(os.str());
    }
    return IteratorRange{next(v.begin(), min(begin, v.size())),
                         next(++v.begin(), min(end, v.size()))};
}



template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    const int range_length = range_end - range_begin;
    if (range_length < 2) {
        return;
    }
    vector<typename RandomIt::value_type> elements(
            make_move_iterator(range_begin), make_move_iterator(range_end));
    auto middle = elements.begin() + range_length / 2;
    MergeSort(elements.begin(), middle);
    MergeSort(middle, elements.end());
    merge(make_move_iterator(elements.begin()), make_move_iterator(middle),
            make_move_iterator(middle), make_move_iterator(elements.end()),
            range_begin);
}
