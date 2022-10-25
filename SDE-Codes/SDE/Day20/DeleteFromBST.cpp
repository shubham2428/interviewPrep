#include <iostream>
#include <queue>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

int findMin(Node *root)
{
    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}
Node *deleteFromBST(Node *root, int val)
{
    if (root->data == val)
    {

        // if have o child

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // have 1child
        // left child

        if (root->right == NULL && root->left != NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child

        if (root->right != NULL &&root->left = NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->right != NULL && root->left != NULL)
        {
            int mini = findMin(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }

        // having both child
    }

    if (root->data > val)
    {
        deleteFromBST(root->left, val);
    }
    else
    {
        deleteFromBST(root->right, val);
    }
}

Node *createBst(Node *root, int data)
{

    if (root == NULL)
    {
        // iska matlab ye phela data hain
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = createBst(root->right, data);
    }

    else
    {
        root->left = createBst(root->left, data);
    }

    return root;
}

void takeInput()
{

    Node *root = NULL;
    cout << "Enter the data for BST" << endl;
    int data;
    cin >> data;
    while (data != -1)
    {
        root = createBst(root, data);
        cin >> data;
    }
}

int main()
{

    takeInput();
}