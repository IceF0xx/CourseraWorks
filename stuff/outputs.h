#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <unordered_set>
#include <deque>

using namespace std;

template <typename K, typename V>
ostream& operator<< (ostream& out, const map<K,V> &m);

template <typename K, typename V>
ostream& operator<< (ostream& out, const pair<K,V>& p);

template <typename K, typename V>
ostream& operator<< (ostream& out, const multimap<K,V>& m);

template <typename F>
ostream& operator<< (ostream& out, const vector<F>& v);

template <typename F>
ostream& operator<< (ostream& out, const deque<F>& v);

template <typename F>
ostream& operator<< (ostream& out, const set<F>& v);

template <typename F>
ostream& operator<< (ostream& out, const unordered_set<F>& v);

template <typename F>
ostream& operator<< (ostream& out, const list<F>& v);


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
ostream& operator<< (ostream& out, const multimap<K,V>& m)
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
    return out << "[" << p.first << " - " << p.second << "]";
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
ostream& operator<< (ostream& out, const deque<F>& v)
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

template <typename F>
ostream& operator<< (ostream& out, const unordered_set<F>& v)
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
ostream& operator<< (ostream& out, const list<F>& v){
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