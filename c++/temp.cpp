#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Queue {
private:
    int front;
    int rear;
    int capacity;
    Node** array;

public:
    Queue(int size) {
        capacity = size;
        front = -1;
        rear = -1;
        array = new Node*[capacity];
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % capacity == front);
    }

    void enqueue(Node* node) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue node." << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        array[rear] = node;

        if (front == -1)
            front = rear;
    }

    Node* dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue node." << endl;
            return nullptr;
        }

        Node* node = array[front];

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;

        return node;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void createTree() {
        int value;
        cout << "\nEnter the root value: ";
        cin >> value;

        if (value == -1) {
            return;
        }

        root = new Node(value);
        Queue queue(100);
        queue.enqueue(root);

        while (!queue.isEmpty()) {
            Node* current = queue.dequeue();

            int leftValue, rightValue;
            cout << "Enter the left child of " << current->data << " (-1 if null): ";
            cin >> leftValue;

            if (leftValue != -1) {
                current->left = new Node(leftValue);
                queue.enqueue(current->left);
            }

            cout << "Enter the right child of " << current->data << " (-1 if null): ";
            cin >> rightValue;

            if (rightValue != -1) {
                current->right = new Node(rightValue);
                queue.enqueue(current->right);
            }
        }
    }

    void inorderTraversal(Node* node) {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(Node* node) {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == nullptr)
            return;

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    int calculateHeight(Node* node) {
        if (node == nullptr)
            return 0;

        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    BinaryTree tree;

    cout << "\nCreate the binary tree:" << endl;
    tree.createTree();

    cout << "\nInorder traversal: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    cout << "\nPreorder traversal: ";
    tree.preorderTraversal(tree.root);
    cout << endl;

    cout << "\nPostorder traversal: ";
    tree.postorderTraversal(tree.root);
    cout << endl;

    int height = tree.calculateHeight(tree.root);
    cout << "\n1Height of the binary tree: " << height << endl;

    return 0;
}