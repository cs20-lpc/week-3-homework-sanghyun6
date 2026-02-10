#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
protected:
    // represents an element in the linked list
    struct Node
    {
        T value;
        Node *next;

        Node(T v = T(), Node *n = nullptr)
            : value(v), next(n) {}
    };

    // a pointer to the front of the list
    Node *head;

    int length;

public:
    // default constructor
    LinkedList();

    // destructor
    virtual ~LinkedList();

    // add the argument to the end of the list
    virtual void append(const T &);

    // remove all elements in the list, resetting to the initial state
    virtual void clear();

    // return the element at the given position (argument)
    virtual T getElement(int) const;

    // return the current length of the list
    virtual int getLength() const;

    // insert the given element (argument 2) at
    // the given position (argument 1)
    virtual void insert(int, const T &) {}

    // determine if the list currently empty
    virtual bool isEmpty() const;

    // remove the element at the given position (argument)
    virtual void remove(int);

    // replace the element at the given position (argument 1) with
    // the value given (argument 2)
    virtual void replace(int, const T &);

    // overloaded stream insertion operator to make printing easier
    template <typename U>
    friend ostream &operator<<(ostream &, const LinkedList<U> &);

    void deleteStudent(int id);
    void displayAll();
    int countStudents();
    void addCourseToStudent(int id, const Course &course);
};

#include "LinkedList.tpp"
#endif