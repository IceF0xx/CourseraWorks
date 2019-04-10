#pragma once
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>

#define RUN_TEST(tr, func) \
    tr.RunTest(func, #func)

using namespace std;



template<class T, class U>
void AssertEqual(const T& t, const U& u,
                 const string& hint);

template <typename K, typename V>
ostream& operator<< (ostream& out, map<K,V> m);

template <typename K, typename V>
ostream& operator<< (ostream& out, pair<K,V> p);

template <typename F>
ostream& operator<< (ostream& out, vector<F> v);

template<class T, class U>
void AssertEqual(const T& t, const U& u,
                 const string& hint);
class TestRunner {
public:
    template <typename TestFunc>
    void RunTest(TestFunc func, const string& test_name);
    ~TestRunner();
private:
    int fail_count = 0;
};

template <typename TestFunc>
void TestRunner::RunTest(TestFunc func, const string& test_name)
{
    try {
        func();
        cerr << test_name << " OK" << endl;
    } catch (runtime_error& e) {
        ++fail_count;
        cerr << test_name << " failed => " << e.what() << endl;
    }
}


template <typename K, typename V>
ostream& operator<< (ostream& out, map<K,V> m)
{
    bool first = true;
    for (const auto& w : m)
    {
        if (!first)
        {
            out << ", ";
        }
        first = false;
        out << w;
    }
    return out;
}

template <typename K, typename V>
ostream& operator<< (ostream& out, pair<K,V> p)
{
    return out << "[" << p.first << ", " << p.second << "]";
}

template <typename F>
ostream& operator<< (ostream& out, vector<F> v)
{
    bool first = true;
    out << '(';
    for (const auto& w : v)
    {
        if (!first)
        {
            out << ", ";
        }
        first = false;
        out << w;
    }
    return out << ')';
}

template <typename F>
ostream& operator<< (ostream& out, set<F> v)
{
    bool first = true;
    out << '(';
    for (const auto& w : v)
    {
        if (!first)
        {
            out << ", ";
        }
        first = false;
        out << w;
    }
    return out << ')';
}

template<class T, class U>
void AssertEqual(const T& t, const U& u,
                 const string& hint)
{
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u
           << " Hint : " << hint;
        throw runtime_error(os.str());
    }
}

