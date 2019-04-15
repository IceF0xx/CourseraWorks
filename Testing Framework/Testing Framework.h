#pragma once
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>

#define RUN_TEST(tr, func) \
    tr.RunTest(func, #func)

#define ASSERT_EQUAL(x, y) {                     \
    ostringstream os;                            \
    os << __FILE__ << ":" << __LINE__;           \
    AssertEqual(x, y, os.str());                 \
    }

#define ASSERT(x) {                              \
    ostringstream os;                            \
    os << __FILE__ << ":" << __LINE__;           \
    Assert(x, os.str());                         \
    }


using namespace std;



template<class T, class U>
void AssertEqual(const T& t, const U& u,
                 const string& hint);

template <typename K, typename V>
ostream& operator<< (ostream& out, const map<K,V> &m);

template <typename K, typename V>
ostream& operator<< (ostream& out, const pair<K,V>& p);

template <typename F>
ostream& operator<< (ostream& out, const vector<F>& v);


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
ostream& operator<< (ostream& out, const map<K,V>& m)
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
ostream& operator<< (ostream& out, const pair<K,V>& p)
{
    return out << "[" << p.first << ", " << p.second << "]";
}

template <typename F>
ostream& operator<< (ostream& out, const vector<F>& v)
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
ostream& operator<< (ostream& out, const set<F>& v)
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
           << " Hint: " << hint;
        throw runtime_error(os.str());
    }
}

template <typename Iterator>
struct IteranorRange{
            Iterator first;
            Iterator second;

            Iterator begin() const {
                return first;
            }
            Iterator end() const {
                return second;
            }
        };


template <typename T>
IteranorRange<typename vector<T>::iterator> Head(vector<T>& v, size_t end){
    if (end < 0 || end >= v.size()){
        ostringstream os;
        os << endl << "incorrect_argument: " << __FILE__ << ":" << __LINE__ + 1;
        throw invalid_argument(os.str());
    }
    return {v.begin(), next(++v.begin(), min(end, v.size()))};
}


template <typename T>
IteranorRange<typename vector<T>::iterator> Head(vector<T>& v, size_t begin, size_t end){
    if (begin > end || end < 0 || end >= v.size() || begin >= v.size() || begin < 0){
        ostringstream os;
        os << endl << "incorrect_argument: " << __FILE__ << ":" << __LINE__ + 1;
        throw invalid_argument(os.str());
    }
    return {next(v.begin(), min(begin, v.size())), next(++v.begin(), min(end, v.size()))};
}

