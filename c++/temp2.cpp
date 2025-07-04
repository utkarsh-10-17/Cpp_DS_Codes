#include <iostream>
//#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class queue
{
public:
    int *arr;
    int size;
    int Front;
    int rear;

    queue()
    {
        size = 100000;
        arr = new int[size];
        Front = 0;
        rear = 0;
    }

    bool empty()
    {
        if (Front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int push(node* root)
    {
        if (rear == size)
        {
            cout << "queue is full " << endl;
        }
        else
        {
            arr[rear] = root->data;
            rear++;
        }
    }

    node* pop(node*root)
    {
        if (Front == rear)
        {
            cout << "queue is empty " << endl;
        }
        else
        {
            arr[Front] = -1;
            Front++;
            if (Front == rear)
            {
                Front = 0;
                rear = 0;
            }
        }
    }

    int front()
    {
        if (Front == rear)
        {
            return -1;
        }
        else
        {
            return arr[Front];
        }
    }

    void print()
    {
        for (int i = Front; i < rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
};

class BinarySearchTree
{
    public:
    node*root = NULL;

node *insertintoBST(node *root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertintoBST(root->right, d);
    }
    else
    {
        root->left = insertintoBST(root->left, d);
    }

    return root;
}

void takeInput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertintoBST(root, data);
        cin >> data;
    }
}

/*node *levelorderTravesal(node *root)
{
    queue q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}*/

 node* levelOrderTraversal() {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
            return NULL;
        }

         queue q;
        q.pop(root);

        cout << "Level-order traversal: ";
        while (!q.empty()) {
            node* temp = q.pop(root);
            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
        cout << endl;
    }

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool searchinBST(node *&root, int x)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    if (root->data > x)
    {
        return searchinBST(root->left, x);
    }
    else
    {
        return searchinBST(root->right, x);
    }
}

/*bool searchinBST(node*root , int x)
{
    node*temp = root;

    while(temp!= NULL)
    {
        if(temp->data == x)
        {
            return true;
        }

        if(temp->data > x)
        {
           temp = temp->left;
        }
        else
        {
           temp = temp->right;
        }
    }
    return false;
}*/

node *MinvalofBST(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *MaxvalofBST(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

node *deletefromBST(node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = MinvalofBST(root->right)->data;
            root->data = mini;
            root->right = deletefromBST(root->right, mini);
            return root;
        }
    }

    else if (root->data > val)
    {
        // left part pe jao
        root->left = deletefromBST(root->left, val);
        return root;
    }
    else
        // right part pe jao
        root->right = deletefromBST(root->right, val);
    return root;
}


    int calculateHeight(node*&root)
     {
        if (root == NULL)
            return 0;

        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        return max(leftHeight, rightHeight) + 1;
    }
};

int main()
{

    BinarySearchTree a;

     
node*root = NULL;


    // 10 8 21 7 27 5 4 3 -1
   

    cout << "Enter data to create BST" << endl;
    a.takeInput(root);

    cout << "printing " << endl;
   a.levelOrderTraversal();

    cout << "Inorder traversal " << endl;
   a. inorder(root);
    cout << endl;
    cout << "preorder traversal " << endl;
   a. preorder(root);
    cout << endl;
    cout << "postorder traversal " << endl;
    a.postorder(root);

    cout << endl;

    cout << "Searching for 7 in BST " << endl;
    cout << a.searchinBST(root, 7);

    cout << endl;

    cout << "Min value is " << a.MinvalofBST(root)->data << endl;
    cout << "Max value is " << a.MaxvalofBST(root)->data << endl;

    cout << endl;

    root = a.deletefromBST(root, 10);

    cout<<"Printing after deleting 10"<<endl;
    a.levelOrderTraversal();

    cout<<endl;

    cout<<"Height of the tree is:"<<a.calculateHeight(root);
    

    return 0;
}