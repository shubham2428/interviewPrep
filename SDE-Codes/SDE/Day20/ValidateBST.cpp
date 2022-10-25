#include<iostream>
using namespace std;

 class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

bool isBST(BinaryTreeNode<int> *root ,  int mini , int maxi){
    
    if(root==NULL){
        return true;
    }
    
    if(root->data >=mini && root->data <=maxi){
        
        bool left= isBST(root->left, mini, root->data);
        
        bool right=isBST(root->right,root->data, maxi);
        
        return left && right;
    }
    
    else{
        return false;
    }
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    
    return isBST(root,INT_MIN,INT_MAX);
}