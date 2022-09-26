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


int CountLeaf(Node* root,int &count){
    if(root==NULL){
        return 0;
    }

    CountLeaf(root->left,count);

    if(root->left==NULL && root->right==NULL){
        count=count+1;
    }

    CountLeaf(root->right, count);

    return count;
}

int main(){
    Node* root=NULL;
    root=buildTree(root);
    int count=0;

    int ans=CountLeaf(root,count);
    cout << ans;

    return 1;

}