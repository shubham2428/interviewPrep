#include <iostream>
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

pair<bool, int> isSumTreeFast(Node *root)
{

    // base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool condn = root->data == leftSum + rightSum;

    pair<bool, int> ans;

    if (isLeftSumTree && isRightSumTree && condn)
    {
        ans.first = true;
        ans.second = root->data + leftSum + rightSum;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

int find_sum(Node *root)
{

    if (root == NULL)

        return 0;

    if (root->left == NULL && root->right == NULL)

        return root->data;

    int left_sum = find_sum(root->left);

    int right_sum = find_sum(root->right);

    if (left_sum + right_sum != root->data)

        return 0;

    else

        return left_sum + right_sum + root->data;
}

bool isSumTree(Node *root)

{

    // Your code here

    if (root == NULL)

        return true;

    if (root->left == NULL && root->right == NULL)

        return true;

    return find_sum(root);
}