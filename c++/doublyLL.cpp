#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insertAthead(Node *&head, Node *&tail, int data)
{

    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAttail(Node *&tail, Node *&head, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtposition(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        insertAthead(head, tail, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    if (temp->next == NULL)
    {
        insertAttail(tail, head, data);
        return;
    }

    while (cnt != position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    Node *nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void getlength(Node *&head)
{
    int length = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    cout << length << endl;
}

void deleteNode(int position, Node *&head)
{
    // deleting first node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        Node *current = head;
        Node *previous = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            previous = current;
            current = current->next;
            cnt++;
        }
        current->prev = NULL;
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
}
int main()
{

    // Node *node1 = new Node(32);

    Node *head = NULL;
    Node *tail = NULL;

    print(head);
    // getlength(head);

    insertAthead(head, tail, 43);
    print(head);

    insertAttail(tail, head, 56);
    print(head);

    insertAtposition(head, tail, 2, 76);
    print(head);

    deleteNode(2, head);
    print(head);

    return 0;
}