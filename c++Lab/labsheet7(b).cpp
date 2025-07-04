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
    int getHeightRecursive(Node *node)
    {
        if (node == NULL)
            return 0;
        int leftHeight = getHeightRecursive(node->left);
        int rightHeight = getHeightRecursive(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }
    int countNodesWithOnlyRightChildRecursive(Node *node)
    {
        if (node == NULL)
            return 0;
        int count = 0;
        if (node->left == NULL && node->right != NULL)
            count++;
        count += countNodesWithOnlyRightChildRecursive(node->left);
        count += countNodesWithOnlyRightChildRecursive(node->right);
        return count;
    }
    void countLeafAndNonLeafNodesRecursive(Node *node, int &leafCount, int &nonLeafCount)
    {
        if (node == NULL)
            return;
        if (node->left == NULL && node->right == NULL)
            leafCount++;
        else
            nonLeafCount++;
        countLeafAndNonLeafNodesRecursive(node->left, leafCount, nonLeafCount);
        countLeafAndNonLeafNodesRecursive(node->right, leafCount, nonLeafCount);
    }
    int findMinElementBSTRecursive(Node *node)
    {
        if (node->left == NULL)
            return node->data;
        return findMinElementBSTRecursive(node->left);
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
    int getHeight()
    {
        return getHeightRecursive(root);
    }
    int countNodesWithOnlyRightChild()
    {
        return countNodesWithOnlyRightChildRecursive(root);
    }
    void countLeafAndNonLeafNodes(int &leafCount, int &nonLeafCount)
    {
        leafCount = 0;
        nonLeafCount = 0;
        countLeafAndNonLeafNodesRecursive(root, leafCount, nonLeafCount);
    }
    int findMinElementBST()
    {
        if (root == nullptr)
        {
            std::cout << "Empty BST." << std::endl;
            return -1;
        }
        return findMinElementBSTRecursive(root);
    }
};
int main()
{
    BinaryTree tree;

    tree.insertNode(2);
    tree.insertNode(1);
    tree.insertNode(3);
    tree.insertNode(5);
    tree.insertNode(21);
    tree.insertNode(31);
    tree.insertNode(25);

    int height = tree.getHeight();
    std::cout << "Height of the binary tree: " << height << std::endl;

    int nodesWithOnlyRightChild = tree.countNodesWithOnlyRightChild();
    std::cout << "Number of nodes having only a right child: " << nodesWithOnlyRightChild << std::endl;

    int leafCount, nonLeafCount;
    tree.countLeafAndNonLeafNodes(leafCount, nonLeafCount);
    std::cout << "Number of leaf nodes: " << leafCount << std::endl;
    std::cout << "Number of non-leaf nodes: " << nonLeafCount << std::endl;

    int minElement = tree.findMinElementBST();
    std::cout << "Minimum element of the BST: " << minElement << std::endl;
    return 0;
}