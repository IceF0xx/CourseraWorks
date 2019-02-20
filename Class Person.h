#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

class Person
{
private:
    struct Fullname
    {
        string Name;
        string Soname;
    };
    map <int, Fullname> Total;
public:
    Person (const string& name, const string& soname, const int& year)
    {
        Total[year].Name = name;
        Total[year].Soname = soname;
    }
    void ChangeFirstName(int year, const string& first_name) {
        if (Total[year].Soname.empty())
        {
            Total[year].Soname ="";
        }
        Total[year].Name = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        if (Total[year].Name.empty())
        {
            Total[year].Name ="";
        }
        Total[year].Soname = last_name;
    }
    string GetFullName(int year) const
    {
        for (const auto& w : Total)
        {
            if (Total.empty() || year < w.first)
            {
                return "No person";
            }
            break;
        }
        string name = "";
        string surname = "";
        for (const auto& w : Total)
        {
            if (year >= w.first && !w.second.Name.empty())
            {
                name = w.second.Name;
            }
            if (year >= w.first && !w.second.Soname.empty())
            {
                surname = w.second.Soname;
            }
        }
        if (name.empty())
        {
            return surname + " with unknown last name";
        }
        else if (surname.empty())
        {
            return name + " with unknown last name";
        }
        else
        {
            return  name + " " + surname;
        }
    }
    string GetFullNameWithHistory(int year) const
    {
        for (const auto& w : Total)
        {
            if (Total.empty() || year < w.first)
            {
                return "No person";
            }
            break;
        }
        string name = "";
        string surname = "";
        vector <string> names;
        vector <string> secondnames;
        for (const auto& w : Total)
        {
            if (year >= w.first && !w.second.Name.empty())
            {
                if (!name.empty() && w.second.Name != name)
                {
                    names.push_back(name);
                }
                name = w.second.Name;
            }
            if (year >= w.first && !w.second.Soname.empty())
            {
                if (!surname.empty() && w.second.Soname != surname)
                {
                    secondnames.push_back(surname);
                }
                surname = w.second.Soname;
            }
        }
        string Totalname = "";
        string Totalsoname = "";
        if (!names.empty())
        {
            Totalname += " (" + names[names.size() - 1];
            if (names.size() > 1)
            {
                for (int i = names.size() - 1; i > 0; i--)
                {
                    Totalname += ", " + names[i - 1] ;
                }
            }
            Totalname += ")";
        }
        if (!secondnames.empty())
        {
            Totalsoname += " (" + secondnames[secondnames.size() - 1];
            if (secondnames.size() > 1)
            {
                for (int i = secondnames.size() - 1; i > 0; i--)
                {
                    Totalsoname += ", " + secondnames[i - 1] ;
                }
            }
            Totalsoname += ")";
        }
        if (name.empty())
        {
            return surname + Totalsoname + " with unknown first name";
        }
        else if (surname.empty())
        {
            return name + Totalname + " with unknown last name";
        }
        else
        {
            return  name + Totalname + " " + surname + Totalsoname;
        }
    }
};

