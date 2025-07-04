#include <iostream>
using namespace std;

class Deque
{
private:
    int front;
    int rear;
    int capacity;
    int *deque;

public:
    Deque(int capacity) : front(-1), rear(-1), capacity(capacity)
    {
        deque = new int[capacity];
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }

    void insertFront(int element)
    {
        if (isFull())
        {
            cout << "Deque is full. Cannot insert element at the front." << std::endl;
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
            }
            else
            {
                front = (front - 1 + capacity) % capacity;
            }
            deque[front] = element;
            cout << "Element " << element << " inserted at the front of the deque." << std::endl;
        }
    }

    void insertRear(int element)
    {
        if (isFull())
        {
            cout << "Deque is full. Cannot insert element at the rear." << std::endl;
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear + 1) % capacity;
            }
            deque[rear] = element;
            cout << "Element " << element << " inserted at the rear of the deque." << std::endl;
        }
    }

    void removeFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. No element to remove from the front." << std::endl;
        }
        else if (front == rear)
        {
            cout << "Element " << deque[front] << " removed from the front of the deque." << std::endl;
            front = rear = -1;
        }
        else
        {
            cout << "Element " << deque[front] << " removed from the front of the deque." << std::endl;
            front = (front + 1) % capacity;
        }
    }

    void removeRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. No element to remove from the rear." << std::endl;
        }
        else if (front == rear)
        {
            cout << "Element " << deque[rear] << " removed from the rear of the deque." << std::endl;
            front = rear = -1;
        }
        else
        {
            cout << "Element " << deque[rear] << " removed from the rear of the deque." << std::endl;
            rear = (rear - 1 + capacity) % capacity;
        }
    }

    void displayDeque()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << std::endl;
        }
        else
        {
            cout << "Elements in the deque: ";
            int i = front;
            while (true)
            {
                cout << deque[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % capacity;
            }
            cout << std::endl;
        }
    }
};

int main()
{
    int capacity;
    cout << "Enter the maximum capacity of the deque: ";
    cin >> capacity;

    Deque deque(capacity);

    deque.insertFront(56);
    deque.insertRear(34);

    deque.isEmpty();
    deque.isFull();
    deque.removeFront();

    return 0;
}
