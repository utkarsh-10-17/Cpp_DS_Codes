#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = next;
    }
};

class stack
{
public:
    Node *top;
    stack()
    {
        top = NULL;
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        if (!temp)
        {
            cout << "stack overflow " << endl;
            return;
        }
        temp->data = data;
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        Node *temp;
        if (top == NULL)
        {
            cout << "Underflow condition " << endl;
            return;
        }
        else
        {
            temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool empty()
    {

        return top = NULL;
    }

    int peek()
    {
        if (!empty())
        {
            return top->data;
        }
        else
        {
            return 1;
        }
    }

    void print()
    {
        Node *temp;
        if (top == NULL)
        {
            cout << "Stack underflow " << endl;
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
                //if (temp != NULL)
               // {
               //     cout << " ";
               // }
            }
        }
    }
};

int main()
{

    stack a;
    a.push(43);
    a.push(32);
    a.push(73);
    a.push(45);
    a.pop();
    a.print();

    return 0;
}