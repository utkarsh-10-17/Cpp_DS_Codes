#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int front;
    int rear;
    int size;
    int capacity;
    int *queue;

public:
    CircularQueue(int capacity) : front(-1), rear(-1), size(0), capacity(capacity)
    {
        queue = new int[capacity];
    }

    ~CircularQueue()
    {
        delete[] queue;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void enqueue(int element)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot insert element." << std::endl;
        }
        else
        {
            rear = (rear + 1) % capacity;
            queue[rear] = element;
            size++;
            cout << "Element " << element << " inserted into the queue." << std::endl;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No element to remove." << std::endl;
        }
        else
        {
            front = (front + 1) % capacity;
            size--;
            cout << "Element " << queue[front] << " removed from the queue." << std::endl;
        }
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << std::endl;
        }
        else
        {
            cout << "Elements in the queue: ";
            int count = 0;
            int i = (front + 1) % capacity;
            while (count < size)
            {
                cout << queue[i] << " ";
                i = (i + 1) % capacity;
                count++;
            }
            cout << std::endl;
        }
    }
};

int main()
{
    int capacity;
    cout << "Enter the maximum capacity of the queue: ";
    cin >> capacity;

    CircularQueue queue(capacity);
    queue.isEmpty();
    queue.isFull();
    queue.displayQueue();

    return 0;
}
