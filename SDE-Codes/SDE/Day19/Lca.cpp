#include<iostream>
#include<queue>
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



Node* lca(Node* root , int x , int y){
    if(root==NULL){
        return root;
    }

    if(root->data ==x || root->data==y){
        return root;
    }

    Node* lans=lca(root->left,x,y);
    Node* rans=lca(root->right,x,y);

    if(lans!=NULL && rans!=NULL){
        return root;
    }

    if(lans==NULL && rans!=NULL){
        return rans;
    }

    if(lans!=NULL && rans==NULL){
        return lans;
    }

    else{
        return NULL;
    }
}
int main(){
    Node* root=NULL;
    root=buildTree(root);

    int x=17;
    int y=7;


    Node* ans=lca(root,x,y);
    cout << ans->data << endl;
}


