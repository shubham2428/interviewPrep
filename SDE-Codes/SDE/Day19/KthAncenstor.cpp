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

Node* KthAncenstor(Node* root,int &k ,Node* testNode){
    if(root==NULL){
        return root;
    }

    if(root->data==testNode->data){
        return root;
    }


    Node*  lans=KthAncenstor(root->left,k,testNode);
    Node* rans=KthAncenstor(root->right,k,testNode);

    if(lans!=NULL && rans==NULL){
        k--;
        if(k<=0){
            // lock ans
            k=INT_MAX;
            return root;
        }

        return lans;
    }

    if(rans!=NULL && lans==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rans;
    }

    return NULL;



}

int main(){
    Node* root=NULL;
    root=buildTree(root);
    int k=2;
    Node* testNode= new Node(4);

    Node* ans= KthAncenstor(root,k,testNode);

    if(ans==NULL || ans==testNode){
        cout << -1;
    }
    else{
    cout << ans->data << endl;
    }
    
    }
