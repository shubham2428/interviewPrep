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

bool SearchIterative(Node *root, int x)
{

    while (root != NULL)
    {
        if (root->data == x)
        {
            return true;
        }
        if (root->data > x)
        {
            root = root->left;
        }

        else
        {
            root = root->right;
        }
    }

    return false;
}

// this is recursive solution
bool SearchRecursive(Node *root, int x)
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
        return SearchRecursive(root->left, x);
    }
    else
    {
        return SearchRecursive(root->right, x);
    }
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

    bool ans = SearchRecursive(root, 20);
    cout << ans << endl;
}

int main()
{

    takeInput();
}