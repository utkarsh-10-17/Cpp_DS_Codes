#include <iostream>
using namespace std;

class queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    queue()
    {
        size = 100000;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int enqueue(int element)
    {
        if (rear == size)
        {
            cout << "queue is full " << endl;
        }
        else
        {
            arr[rear] = element;
            rear++;
        }
    }

    int dequeue()
    {
        if (front == rear)
        {
            cout << "queue is empty " << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int isfront()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    void print()
    {
        for (int i = front; i < rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{

    queue a;
    a.enqueue(43);
    a.enqueue(45);
    a.enqueue(76);
    a.enqueue(21);
    a.print();
    cout<<endl;
    cout << a.isfront();
    cout<<endl;
    cout << a.isEmpty();
    cout<<endl;
    a.dequeue();
    a.dequeue();
    cout<<endl;
    cout << a.isfront();
    cout<<endl;
    a.print();

    return 0;
}