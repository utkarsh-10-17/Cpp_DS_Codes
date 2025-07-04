#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

class circularQueue
{
private:
    Node *front;
    Node *rear;

public:
    circularQueue()
    {
        front = rear = nullptr;
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);
        newNode->data = data;
        newNode->next = nullptr;

        if (front == nullptr)
        {
            front = rear = newNode;
            rear->next = front;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }

        cout << data << " has been inserted " << endl;
    }

    void Delete()
    {
        if (front == nullptr)
        {
            cout << "The queue is empty " << endl;
        }
        else if (front == rear)
        {
            Node *temp = front;
            front = rear = nullptr;
            delete temp;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node *temp = front;
            cout << "Circular Queue: ";
            do
            {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != front);
            cout << endl;
        }
    }
};

int main()
{
    circularQueue a;

    a.insert(32);
    a.insert(35);
    a.insert(21);
    a.insert(4);
    a.insert(73);
    a.display();
    a.Delete();
    a.display();
    a.Delete();
    a.display();
    return 0;
}