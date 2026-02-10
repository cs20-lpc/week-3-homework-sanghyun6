// TODO:  Course class definitins go here.
#ifndef COURSE_HPP
#define COURSE_HPP
#include <string>
using namespace std;

class Course
{
private:
    string name;
    string location;

public:
    Course(const string &courseName, const string &courseLocation);
    string getName() const;
    string getLocation() const;

    void display() const;
};

#endif