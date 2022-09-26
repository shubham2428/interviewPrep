#include<iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;

    cout << "Enter the data" << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter the value for left child of " << data << endl;

    root->left = buildTree(root->left);

    cout << "Enter the right child for " << data << endl;

    root->right = buildTree(root->right);

    return root;
}


 bool isIdentical(Node *r1, Node *r2)
    {
        // base case
        if(r1 == NULL && r2 == NULL) {
            return true;
        }
        
        if(r1 == NULL && r2 != NULL) {
            return false;
        }
        
        if(r1 != NULL && r2 == NULL) {
            return false;
        }
        
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        
        bool value = r1->data == r2->data;
        
        
        if(left && right && value) {
            return true;
        }
        else
        {
            return false;
        }
        
    }


