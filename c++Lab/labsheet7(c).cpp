#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Queue
{
private:
    int front;
    int rear;
    int capacity;
    Node **array;

public:
    Queue(int size)
    {
        capacity = size;
        front = -1;
        rear = -1;
        array = new Node *[capacity];
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % capacity == front);
    }

    void enqueue(Node *node)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue node." << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        array[rear] = node;

        if (front == -1)
            front = rear;
    }

    Node *dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue node." << endl;
            return nullptr;
        }

        Node *node = array[front];

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;

        return node;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = NULL;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (root == NULL)
        {
            root = newNode;
            return;
        }

        Queue queue(1000);
        queue.enqueue(root);

        while (!queue.isEmpty())
        {
            Node *current = queue.dequeue();

            if (current->left == NULL)
            {
                current->left = newNode;
                return;
            }
            else
            {
                queue.enqueue(current->left);
            }

            if (current->right == NULL)
            {
                current->right = newNode;
                return;
            }
            else
            {
                queue.enqueue(current->right);
            }
        }
    }

    void levelOrderTraversal()
    {
        if (root == NULL)
        {
            cout << "Tree is empty." << endl;
            return;
        }

        Queue queue(100);
        queue.enqueue(root);

        cout << "Level-order traversal: ";
        while (!queue.isEmpty())
        {
            Node *current = queue.dequeue();
            cout << current->data << " ";

            if (current->left != NULL)
                queue.enqueue(current->left);

            if (current->right != NULL)
                queue.enqueue(current->right);
        }
        cout << endl;
    }

    void inorderTraversal(Node *node)
    {
        if (node == NULL)
            return;

        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(Node *node)
    {
        if (node == NULL)
            return;

        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    int calculateHeight(Node *node)
    {
        if (node == NULL)
            return 0;

        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        return max(leftHeight, rightHeight) + 1;
    }
};

int main()
{
    BinaryTree tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    tree.levelOrderTraversal();

    cout << "Inorder traversal: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorderTraversal(tree.root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorderTraversal(tree.root);
    cout << endl;

    int height = tree.calculateHeight(tree.root);
    cout << "Height of the binary tree: " << height << endl;

    return 0;
}
