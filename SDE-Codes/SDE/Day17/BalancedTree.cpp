#include<iostream>
using namespace std;

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


pair<bool, int> isBalancedFast(Node* root) {
                // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second ) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff) {
           ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }

int isBalanced(Node* root){
    if(root==NULL){
        return 0;
    }

    int lh=isBalanced(root->left);

    if(lh==-1){
        return -1;

    }

    int rh=isBalanced(root->right);

    if(rh==-1){
        return -1;
    }

    if(abs(lh-rh)>1){
        return -1;
    }

    return 1 + max(lh,rh);
}


int main(){
    Node* root=NULL;

    root=buildTree(root);

    int ans=isBalanced(root);

   if(ans!=-1){
    cout << "true";
   }
   else{
    cout << "false";
   }
}