#include <iostream>
using namespace std;

class Node {
    public:
    string name;
    string dob;
    int age;
    Node* next;
};

class CircularQueue {
private:
    Node* rear;

public:
    CircularQueue() : rear(nullptr) {}

    bool isEmpty() {
        return rear == nullptr;
    }

    void enqueue(string name, string dob, int age) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->dob = dob;
        newNode->age = age;

        if (isEmpty()) {
            newNode->next = newNode;
            rear = newNode;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Person enqueued successfully." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No person to dequeue." << endl;
            return;
        }

        Node* temp = rear->next;

        if (rear->next == rear) {
            rear = nullptr;
        } else {
            rear->next = rear->next->next;
        }

        cout << "Person dequeued successfully." << endl;
        delete temp;
    }

    int countSeniorCitizens() {
        if (isEmpty()) {
            return 0;
        }

        int count = 0;
        Node* current = rear;

        do {
            if (current->age >= 60) {
                count++;
            }
            current = current->next;
        } while (!(current == rear));

        return count;
    }
};

int main() {
    CircularQueue queue;
 
    queue.enqueue("manan", "1997-07-10", 28);
    queue.enqueue("ayush", "1987-06-12", 46);
    queue.enqueue("chris", "1965-11-30", 69);
    queue.enqueue("karl", "1956-03-15", 47);

     
    queue.dequeue();  

   
    int seniorCitizenCount = queue.countSeniorCitizens();
    cout << "Senior Citizens in the queue: " << seniorCitizenCount << endl;

    return 0;
}