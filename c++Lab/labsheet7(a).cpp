#include <iostream>
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
class BinaryTree
{
private:
    Node *root;
    Node *findNode(Node *current, int value)
    {
        if (current == NULL || current->data == value)
            return current;
        Node *leftResult = findNode(current->left, value);
        if (leftResult != NULL)
            return leftResult;
        Node *rightResult = findNode(current->right, value);
        return rightResult;
    }
    Node *findMinimum(Node *current)
    {
        while (current->left != NULL)
            current = current->left;
        return current;
    }

public:
    BinaryTree()
    {
        root = NULL;
    }
    void insertNode(int value)
    {
        Node *newNode = new Node(value);
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node *current = root;
            while (true)
            {
                if (value < current->data)
                {
                    if (current->left == NULL)
                    {
                        current->left = newNode;
                        break;
                    }
                    current = current->left;
                }
                else
                {
                    if (current->right == NULL)
                    {
                        current->right = newNode;
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }
    Node *findInorderSuccessor(int value)
    {
        Node *current = findNode(root, value);
        if (current == NULL)
            return NULL;
        if (current->right != NULL)
            return findMinimum(current->right);
        Node *successor = NULL;
        Node *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
};
int main()
{
    BinaryTree tree;
    tree.insertNode(6);
    tree.insertNode(1);
    tree.insertNode(3);
    tree.insertNode(5);
    tree.insertNode(15);
    tree.insertNode(34);
    tree.insertNode(12);
    int targetNode;
    std::cout << "Enter the value of the node to find its inorder successor: ";
    std::cin >> targetNode;
    Node *successor = tree.findInorderSuccessor(targetNode);
    if (successor != NULL)
    {
        std::cout << "Inorder Successor of " << targetNode << " is " << successor->data << std::endl;
    }
    else
    {
        std::cout << "Inorder Successor not found for " << targetNode << std::endl;
    }
    return 0;
}