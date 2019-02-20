#include <iostream>
#include <string>
#include <map>
#include <set>

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (runtime_error& e) {
            ++fail_count;
            cerr << test_name << " failed => " << e.what() << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << "In UNIT-test was found " << fail_count << (fail_count > 1 ? " errors" : " error") << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

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
    for (const auto& w : v)
    {
        if (!first)
        {
            out << ", ";
        }
        first = false;
        out << v;
    }
    return out;
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

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}