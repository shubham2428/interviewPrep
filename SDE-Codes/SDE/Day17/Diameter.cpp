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


int Height(Node* root, int &d){
    if(root==NULL){
        return 0;
    }

    int lh=Height(root->left,d);
    int rh=Height(root->right,d);

    d=max(d,lh+rh);

    return 1 + max(lh,rh);
}

int CalDiameter(Node* root){
    int diamter=0;
    Height(root,diamter);
    return diamter;

}

int main(){
    Node* root=NULL;
    root=buildTree(root);
    int ans=CalDiameter(root);
    cout << ans;

    return 1;




}