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


int Height(Node* root){

    if(root==NULL){
        return 0;
    }

    int leftHeight=Height(root->left);

    int rightHeight=Height(root->right);

    int totalHeight=max(leftHeight,rightHeight)+1;

    return totalHeight;

}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int height=Height(root);

    cout << height << endl;

    return 1;
}