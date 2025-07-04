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
    ~node()
    {
    }
};
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
void combine(node *&head1, node *&tail1, node *&head2, node *&tail2)
{
    tail1->next = head2;
    tail1 = tail2;
}
void sort(node *&head1, node *&tail1)
{
    node *cur = head1;
    while (cur != NULL)
    {
        node *now = cur->next;
        while (now != NULL)
        {
            if (cur->data > now->data)
            {
                swap(cur->data, now->data);
            }
            now = now->next;
        }
        cur = cur->next;
    }
}
int main()
{
    node *head1 = NULL;
    node *tail1 = NULL;
    intail(head1, tail1, 4);
    intail(head1, tail1, 6);
    intail(head1, tail1, 2);
    intail(head1, tail1, 1);
    cout << "linked list 1 " << endl;
    print(head1, tail1);
    sort(head1, tail1);
    print(head1, tail1);
    node *head2 = NULL;
    node *tail2 = NULL;
    intail(head2, tail2, 69);
    intail(head2, tail2, 27);
    intail(head2, tail2, 10);
    intail(head2, tail2, 17);
    cout << "linked list 2 " << endl;
    print(head2, tail2);
    combine(head1, tail1, head2, tail2);
    cout << " merge linked list  " << endl;
    print(head1, tail1);
}