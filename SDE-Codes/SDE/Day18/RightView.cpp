#include <iostream>
#include <vector>
#include <queue>
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


void RightViewLevelOrder(Node* root, vector<int> &ans){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    ans.push_back(root->data);

    while(!q.empty()){
        Node* top=q.front();
        q.pop();

        if(top==NULL){
            if(!q.empty()){
                int val=(q.back())->data;
                 ans.push_back(val);
                q.push(NULL);
            }
        }

        else{

            if(top->left){
                q.push(top->left);
            }

            if(top->right){
                q.push(top->right);
            }
        }
    }

}


void RightView(Node *root, vector<int> &ans, int level)
{

    if (root == NULL)
    {
        return;
    }

    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }

    RightView(root->right, ans, level + 1);
    RightView(root->left, ans, level + 1);
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    vector<int> ans;
    int level = 0;

    RightView(root, ans, level);

    for (auto i : ans)
    {
        cout << i << endl;
    }
}