#include <iostream>
using namespace std;

class Student
{
public:
    int roll;
    int marks;
    Student *next;
};

class LinkedList
{
public:
    LinkedList() : head(NULL) {}
    ~LinkedList()
    {
        while (head != NULL)
        {
            Student *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add_student(int roll, int marks)
    {
        Student *new_node = new Student{roll, marks, NULL};
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            Student *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    int *find_students(int &size)
    {
        int *roll_numbers = new int[60];
        int i = 0;
        Student *current = head;
        while (current != NULL)
        {
            if (current->marks < 4)
            {
                roll_numbers[i++] = current->roll;
            }
            current = current->next;
        }
        size = i;
        return roll_numbers;
    }

    Student *head;
};

int main()
{
    LinkedList temp;
    temp.add_student(1, 12);
    temp.add_student(2, 13);
    temp.add_student(3, 3);
    temp.add_student(4, 2);
    temp.add_student(5, 1);

    int size;
    int *roll_numbers = temp.find_students(size);

    for (int i = 0; i < size; i++)
    {
        cout << roll_numbers[i] << " ";
    }

    return 0;
}