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
        this->next = NULL;
    }
};

// New node create at head
void InsertatHead(Node *&Head, int d)
{
    Node *temp = new Node(d);
    temp->next = Head;
    Head = temp;
}

// Printing node
void print(Node *&Head)
{
    Node *temp = Head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Inserting at tail
void Insertattail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void Insertatposition(Node *&Head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        InsertatHead(Head, d);
        return;
    }
    Node *temp = Head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        Insertattail(tail, d);
        return;
    }

    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

//void deleteNode(int position , node*&Head)

int main()
{
    // New node created
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // Head Pointed to node1
    Node *Head = node1;
    Node *tail = node1;
    print(Head);

    // InsertatHead(Head, 12);
    // print(Head);

    // InsertatHead(Head, 15);
    // print(Head);

    Insertattail(tail, 11);
    print(Head);
    Insertattail(tail, 83);
    print(Head);

    Insertatposition(Head, tail, 3, 22);
    print(Head);

    Insertatposition(Head, tail, 1, 30);
    print(Head);

    Insertatposition(Head, tail, 6, 44);
    print(Head);

    cout << "head " << Head->data << endl;
    cout << "tail  " << tail->data << endl;

    return 0;
}