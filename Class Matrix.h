#pragma once

#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Matrix
{
public:
    Matrix();
    Matrix(const int& rows, const int& columns);
    void Reset(const int& rows, const int& columns);
    int At(const int& rows, const int& columns) const;
    int& At(const int& rows, const int& columns);
    int GetNumRows() const;
    int GetNumColumns() const;
private:
    int col;
    int row;
    vector <vector<int>> The_matrix;
};

