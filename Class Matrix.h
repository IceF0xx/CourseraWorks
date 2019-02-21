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
    Matrix()
    {
        col = 0;
        row = 0;
    }
    Matrix(const int& rows, const int columns)
    {
        Reset(rows, columns);
    }
    void Reset(const int& rows, const int columns)
    {
        if (rows < 0 || columns < 0)
        {
            throw out_of_range("Rows or columns are < 0");
        }
        col = columns;
        row = rows;
        The_matrix.assign(rows,vector<int>(columns));
    }
    int At(const int& rows, const int columns) const
    {
        return The_matrix.at(rows).at(columns);
    }
    int& At(int& rows, int columns)
    {
        return The_matrix.at(rows).at(columns);
    }
    int GetNumRows() const
    {
        return row;
    }
    int GetNumColumns() const
    {
        return col;
    }
private:

    int col;
    int row;
    vector <vector<int>> The_matrix;
};

bool operator==(Matrix& rhs, Matrix& lhs)
{
    if (rhs.GetNumColumns() != lhs.GetNumColumns() || rhs.GetNumRows() != lhs.GetNumRows())
    {
        return false;
    }
    for (int row = 0; row < rhs.GetNumRows(); row++)
    {
        for (int col = 0; col < rhs.GetNumColumns(); col++)
        {
            if (rhs.At(row,col) != lhs.At(row,col))
            {
                return false;
            }
        }
    }
    return true;
}

Matrix operator+(Matrix& rhs, Matrix& lhs)
{
    if (rhs.GetNumColumns() != lhs.GetNumColumns() || rhs.GetNumRows() != lhs.GetNumRows())
    {
        throw invalid_argument("Defferent sizes of matrixes");
    }
    Matrix result(rhs.GetNumRows(), rhs.GetNumColumns());
    for (int row = 0; row < rhs.GetNumRows(); row++)
    {
        for (int col = 0; col < rhs.GetNumColumns(); col++)
        {
            result.At(row, col) = rhs.At(row, col) + lhs.At(row, col);
        }
    }
    return result;
}

istream& operator>>(istream& in, Matrix& matrix)
{
    int row,col;
    in >> row >> col;
    matrix.Reset(row,col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++) {
            in >> matrix.At(i,j);
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix)
{
    out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
    for (int row = 0; row < matrix.GetNumRows(); row++)
    {
        for (int col = 0; col < matrix.GetNumColumns(); col++)
        {
            if (col > 0)
            {
                out << " ";
            }
            out << matrix.At(row,col);
        }
        out << endl;
    }
    return out;
}
