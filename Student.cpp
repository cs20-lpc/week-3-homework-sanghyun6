// TODO:  Student class methods implementation here.
#include "Student.hpp"
#include <iostream>
using namespace std;

Student::Student(int studentId, const string &studentName, double studentGPA)
{
    id = studentId;
    name = studentName;
    gpa = studentGPA;
    courseCount = 0;
}

int Student::getId() const
{
    return id;
}

string Student::getName() const
{
    return name;
}

double Student::getGPA() const
{
    return gpa;
}

void Student::display() const
{
    cout << id << " " << name << " " << gpa << endl;

    if (courseCount == 0)
    {
        cout << "None" << endl;
    }
    else
    {
        cout << "Courses:" << endl;
        for (int i = 0; i < courseCount; i++)
        {
            cout << "    ";
            courses[i]->display();
        }
    }
}

void Student::addCourse(const Course *c)
{
    if (courseCount < 10)
    {
        courses[courseCount++] = c;
    }
    else
    {
        cout << "Cannot add more courses, maximum reached." << endl;
    }
}