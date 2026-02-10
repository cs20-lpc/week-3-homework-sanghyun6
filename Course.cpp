// TODO:  Course class methods implementation here.
#include "Course.hpp"
#include <iostream>
using namespace std;

Course::Course(const string &courseName, const string &courseLocation)
{
    name = courseName;
    location = courseLocation;
}

string Course::getName() const
{
    return name;
}

string Course::getLocation() const
{
    return location;
}

void Course::display() const
{
    cout << name << " " << location << endl;
}