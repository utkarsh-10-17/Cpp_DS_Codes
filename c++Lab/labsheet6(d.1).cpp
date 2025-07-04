#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    node()
    {
    }

    void intail(node *&head, node *&tail, int d)
    {
        if (head == NULL)
        {
            node *temp = new node(d);
            head = temp;
            tail = temp;
        }
        else
        {
            node *temp = new node(d);
            tail->next = temp;
            tail = temp;
        }
    }
    void print(node *&head, node *&tail)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    node *reverse(node *&head, node *&tail)
    {
        node *cur = head;
        node *pre = NULL;
        while (cur != NULL)
        {
            node *forward = cur->next;
            cur->next = pre;
            pre = cur;
            cur = forward;
        }
        return pre;
    }
};
int main()
{
    node n;
    node *head = NULL;
    node *tail = NULL;

    n.intail(head, tail, 9);

    n.intail(head, tail, 10);

    n.intail(head, tail, 11);

    n.intail(head, tail, 17);
    n.print(head, tail);
    node *Head = n.reverse(head, tail);
    n.print(Head, tail);
}