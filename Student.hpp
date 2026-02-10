// TO DO:  Student class definition  here.

#include <string>
#include "Course.hpp"
using namespace std;

class Student
{
private:
    int id;
    string name;
    double gpa;

    const Course *courses[10];
    int courseCount;

public:
    Student(int studentId, const string &studentName, double studentGPA);

    int getId() const;
    string getName() const;
    double getGPA() const;

    void display() const;
    void addCourse(const Course *c);
};