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
    ~Node()
    {
        int value = this->data;
        cout << " memory is free for " << value << endl;
    }
};
void insetathead(Node *&head, int d, Node *&tail)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}
void insetattail(Node *&tail, int d, Node *&head)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}
void insertatpos(int position, Node *&head, int d, Node *&tail)
{
    if (position == 1)
    {

        insetathead(head, d, tail);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < (position - 1))
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insetattail(tail, d, head);
        return;
    }
    Node *insert = new Node(d);

    insert->next = temp->next;
    temp->next = insert;
}
void deletenum(Node *&head, Node *&tail, int n)
{
    if (n == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {

        Node *current = head;
        Node *prev = NULL;
        int count = 1;
        while (count < n)
        {
            prev = current;
            current = current->next;

            count++;
        }
        if (current->next == NULL)
        {
            tail = prev;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

void search(Node *&head, int d)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == d)
        {
            cout << "element is present " << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "element is not present " << endl;
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
int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;
    Node *head = NULL;
    Node *tail = NULL;
    insetathead(head, 7, tail);

    insetattail(tail, 2, head);
    insertatpos(1, head, 5, tail);

    insertatpos(6, head, 3, tail);
    print(head);
    int d;
    cout << "element want to search " << endl;
    cin >> d;
    search(head, d);

    return 0;
}