#include <iostream>
using namespace std;

class queue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    queue()
    {
        size = 10000000;
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
            cout << "Queue is full " << endl;
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

    int Front()
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

    a.enqueue(54);
    a.enqueue(52);
    a.enqueue(77);

    a.print();

    a.dequeue();

    a.print();

    return 0;
}