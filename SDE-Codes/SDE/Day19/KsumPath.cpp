#include<iostream>
#include<vector>
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


void kSumPath(Node* root, int &count,vector<int> path, int k){

    if(root==NULL){
        return ;
    }

    path.push_back(root->data);
    
    kSumPath(root->left,count,path,k);
    kSumPath(root->right,count,path,k);

    int size=path.size();
    int sum=0;

    for(int i =size-1;i>=0;i--){
        sum+=path[i];

        if(sum==k){
            count++;
        }
    }

    path.pop_back();

}
int main(){
    Node* root=NULL;
    root=buildTree(root);

    int count=0;
    vector<int> path;
    int k=3;

    kSumPath(root,count,path , k);

    cout << count;
};