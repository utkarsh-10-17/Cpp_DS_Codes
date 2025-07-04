#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

void insert(Node** head, int data) {
    Node* newNode = new Node(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD" << endl;
}

Node* deleteNodes(Node* head, int key) {
    if (head == NULL)
        return NULL;

    Node* curr = head;
    Node* prev = NULL;

    while (curr->next != head) {
        if (curr->data == key) {
            if (prev == NULL) {  
                Node* last = head;
                while (last->next != head)
                    last = last->next;

                head = curr->next;
                last->next = head;
                delete curr;
                curr = head;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    // Check for deletion of last node
    if (curr->data == key) {
        if (prev == NULL) {  // Only one node is present
            delete curr;
            return NULL;
        } else {
            prev->next = curr->next;
            delete curr;
            return prev->next;
        }
    }

    return head;
}

int main() {
    Node* head = NULL;

  
    insert(&head, 3);
    insert(&head, 1);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 4);

    cout << "Original Circular Linked List: ";
    display(head);

    int key = 7;
    head = deleteNodes(head, key);

    cout << "Updated Circular Linked List after deletion of nodes with data " << key << ": ";
    display(head);
return 0;
}