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

        cout << endl;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void InsertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtposition(Node *&tail, Node *&head, int position, int data)
{
    if (position == 1)
    {
        InsertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    while (cnt != position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    Node *nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void deleteNode(int position, Node *&head)
{
    // deleting first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free first node
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
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

  
int main()
{

    Node *node1 = new Node(12);
    //  cout<<node1->data<<endl;
    //  cout<<node1->next<<endl;

    // currently head point towards node1
    Node *head = node1;
    // as at first only a single node is present in LL therefore the tail
    // pointer will point to node1
    Node *tail = node1;

    print(head);
    InsertAtHead(head, 32);
    print(head);

    InsertAtHead(head, 54);
    print(head);

    insertAtTail(tail, 34);
    print(head);

    insertAtposition(tail, head, 5, 47);
    print(head);

  cout << endl;

  cout << "head" << head->data << endl;
     cout << "tail" << tail->data << endl;

    deleteNode(3, head);
   
    print(head);

    return 0;

}