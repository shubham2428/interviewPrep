#include <iostream>
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

void LevelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *top = q.front();
        q.pop();

        if (top == NULL)
        {
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else
        {
            cout << top->data;

            if (top->left)
            {
                q.push(top->left);
            }

            if (top->right)
            {
                q.push(top->right);
            }
        }
    }
}


void buildFromLevelOrder(Node* &root) {
    queue<Node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new Node(data);
    
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp->right);
        }
    }
 }




void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main()
{

    Node *root = NULL;
    root = buildTree(root);
    // inorder(root);

    LevelOrderTraversal(root);
}