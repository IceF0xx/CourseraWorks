#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
//#include "Testing Framework/Testing Framework.h"
using namespace std;

vector<string> SplitIntoWords(const string& s);

template <typename It>
void PrintVector(It range_begin,
                 It range_end)
{
    for (auto it = --range_end; it >= range_begin; --it)
    {
        cout << *it << " ";
    }
}

vector<string> SplitIntoWords(const string& s)
{
    string s1 = s;
    vector<string> result;
    while (!s1.empty())
    {
        string temp;
        auto space = find(s1.begin(), s1.end(), ' ');
        for (auto it = s1.begin(); it != space; ++it)
        {
            temp += *it;
        }
        result.push_back(temp);
        if (space == s1.end())
        {
            break;
        }
        s1.erase(s1.begin(), ++space);

    }
    return result;
}

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;
    return 0;
}
