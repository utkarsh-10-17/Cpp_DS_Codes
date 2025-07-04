#include <iostream>
using namespace std;

class stack
{
public:
    int *arr;
    int size;
    int top;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack Underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{

    stack st(5);

    st.push(32);
    st.push(34);
    st.push(56);

    cout << st.peek() << endl;

    st.pop();

    cout << "The element at top is " << st.peek() << endl;

    cout << st.isEmpty();

    return 0;
}