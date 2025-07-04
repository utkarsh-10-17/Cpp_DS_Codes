#include <iostream>
using namespace std;

class student
{
protected:
    int roll_number;

public:
    void get_number(int);
    void put_number(void);
};

void student ::get_number(int a)
{
    roll_number = a;
}
void student ::put_number()
{
    cout << "Roll Number: " << roll_number << endl;
}
class test : public student
{
protected:
    float sub1;
    float sub2;

public:
    void get_marks(float, float);
    void put_marks(void);
};

void test ::get_marks(float x, float y)
{
    sub1 = x;
    sub2 = y;
}
void test ::put_marks()

{
    cout << "marks in SUB1 = " << sub1 << endl;
    cout << "marks in SUB2 = " << sub2 << endl;
}

class sports
{
public:
    int sportsMarks;
    void get_sports(int);
    void put_sports(void);
};

void sports ::get_sports(int p)
{
    sportsMarks = p;
}
void sports::put_sports()
{
    cout << "marks in Sports = " << sportsMarks << endl;
}

class result : public test, public sports
{
    float total;

public:
    void display(void);
};
void result ::display(void)
{
    total = sub1 + sub2 + sportsMarks;
    put_number();
    put_marks();
    put_sports();
    cout << "Total = " << total << endl;
}

int main()
{
    result student1;
    student1.get_number(327);
    student1.get_marks(64, 56);
    student1.get_sports(47);

    student1.display();
    return 0;
}