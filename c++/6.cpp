#include <iostream>
using namespace std;

class student
{
    int rollNo;

public:
    void setData1(int i)
    {

        rollNo = i;
    }

    void display1()
    {

        cout << "The roll number of the student is: " << rollNo << endl;
    }
};

class Result : public student
{
    int marks_s1;
    int marks_s2;
    int total;

public:
    void setData2(int a, int b, int t)
    {
        marks_s1 = a;
        marks_s2 = b;
        total = t;
    }

    void display2()
    {
        cout << "Marks of the student in subject1 is " << marks_s1 << endl;
        cout << "Marks of the student in subject2 is " << marks_s2 << endl;
        cout << "The total marks of the student is " << marks_s1 + marks_s2 << endl;
    }
};
int main()
{
    student utkarsh;
    utkarsh.setData1(24);
    utkarsh.display1();

    Result Marks;
    Marks.setData2(28, 32, 00);
    Marks.display2();

    return 0;
}