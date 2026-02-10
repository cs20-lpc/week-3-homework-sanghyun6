#include <iostream>
#include <string>
#include "Student.hpp"

// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.

#include "LinkedList.hpp"

using namespace std;

int main()
{
  // TO DO: Insert your code to display a menu for user to select to add/delete/view Student and course information.
  LinkedList<Student> studentList; // LinkedList 객체 생성
  int choice;

  do
  {
    // 메뉴 출력
    cout << "\n===== Student Management System =====" << endl;
    cout << "1. Insert Student" << endl;
    cout << "2. Delete Student" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Display All" << endl;
    cout << "5. Count Students" << endl;
    cout << "6. Add a course" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      // 학생 추가
      int id;
      string name;
      double gpa;

      cout << "Enter ID: ";
      cin >> id;
      cin.ignore(); // 버퍼 클리어
      cout << "Enter Name: ";
      getline(cin, name);
      cout << "Enter GPA: ";
      cin >> gpa;

      Student newStudent(id, name, gpa);
      studentList.append(newStudent);
      break;
    }

    case 2:
    {
      // 학생 삭제
      int id;
      cout << "Enter ID to delete: ";
      cin >> id;
      studentList.deleteStudent(id);
      break;
    }

    case 3:
    {
      // 학생 검색
      int id;
      cout << "Enter ID to search: ";
      cin >> id;
      studentList.getElement(id);
      break;
    }

    case 4:
    {
      // 모든 학생 출력
      studentList.displayAll();
      break;
    }

    case 5:
    {
      // 학생 수 출력
      cout << "Total students: " << studentList.countStudents() << endl;
      break;
    }

    case 6:
    {
      // 코스 추가
      int id;
      string courseName, location;

      cout << "Enter ID: ";
      cin >> id;
      cin.ignore();
      cout << "Enter Course Name: ";
      getline(cin, courseName);
      cout << "Enter location: ";
      getline(cin, location);

      Course newCourse(courseName, location);
      studentList.addCourseToStudent(id, newCourse);
      break;
    }

    case 7:
      cout << "Exiting program..." << endl;
      break;

    default:
      cout << "Invalid choice! Please try again." << endl;
    }

  } while (choice != 7);

  return 0;
}
