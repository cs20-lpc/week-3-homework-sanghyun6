
#include <iostream>
using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
    : head(nullptr), length(0) {}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
void LinkedList<T>::append(const T &elem)
{
    Node *newNode = new Node(elem, nullptr);

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    this->length++;
}

template <typename T>
void LinkedList<T>::clear()
{
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = nullptr;
    this->length = 0;
}

template <typename T>
T LinkedList<T>::getElement(int position) const
{
    Node *curr = head;
    if (position < 0 || position >= this->length)
    {
        throw string("Invalid position");
    }
    for (int i = 0; i < position; i++)
    {
        curr = curr->next;
    }
    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const
{
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T &elem)
{
    Node *curr = head;
    if (position < 0 || position >= this->length)
    {
        throw string("Invalid position");
    }
    for (int i = 0; i < position; i++)
    {
        curr = curr->next;
    }
    curr->value = elem;
}

template <typename T>
ostream &operator<<(ostream &outStream, const LinkedList<T> &myObj)
{
    if (myObj.isEmpty())
    {
        outStream << "List is empty, no elements to display.\n";
    }
    else
    {
        typename LinkedList<T>::Node *curr = myObj.head;
        while (curr != nullptr)
        {
            outStream << curr->value;
            if (curr->next != nullptr)
            {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}

// added

template <typename T>
void LinkedList<T>::remove(int position)
{
    if (position < 0 || position >= this->length)
    {
        throw string("Invalid position");
    }

    if (position == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node *curr = head;
        for (int i = 0; i < position - 1; i++)
        {
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    this->length--;
}

template <typename T>
void LinkedList<T>::deleteStudent(int id)
{
    Node *curr = head;
    int position = 0;

    while (curr != nullptr)
    {
        if (curr->value.getId() == id)
        {
            remove(position);
            cout << "Deleted student with ID " << id << endl;
            return;
        }
        curr = curr->next;
        position++;
    }
    cout << "Student with ID " << id << " not found!" << endl;
}

template <typename T>
void LinkedList<T>::displayAll()
{
    if (isEmpty())
    {
        cout << "No students in the list." << endl;
        return;
    }

    cout << "Students in List:" << endl;
    Node *curr = head;
    while (curr != nullptr)
    {
        curr->value.display();
        curr = curr->next;
    }
}

template <typename T>
int LinkedList<T>::countStudents()
{
    return getLength();
}

template <typename T>
void LinkedList<T>::addCourseToStudent(int id, const Course &course)
{
    Node *curr = head;

    while (curr != nullptr)
    {
        if (curr->value.getId() == id)
        {
            const Course *coursePtr = new Course(course);
            curr->value.addCourse(coursePtr);
            return;
        }
        curr = curr->next;
    }
    cout << "Student with ID " << id << " not found!" << endl;
}