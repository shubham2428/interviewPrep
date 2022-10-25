#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void inorder(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> in;
    inorder(root, in);
    int n = in.size();
    TreeNode<int> *head = new TreeNode<int>(in[0]);
    TreeNode<int> *currRoot = head;

    for (int i = 1; i < n; i++)
    {
        TreeNode<int> *newRoot = new TreeNode<int>(in[i]);

        currRoot->left = NULL;
        currRoot->right = newRoot;
        currRoot = newRoot;
    }

    currRoot->left = NULL;
    currRoot->right = NULL;

    return head;
}
