#include <iostream>
#include <queue>
#include <unordered_map>
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

unordered_map<int, int> BottomView(Node *root)
{
    if (root == NULL)
    {
        return {{0, 0}};
    }

    queue<pair<Node *, int>> q;

    unordered_map<int, int> topNode;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> top = q.front();
        q.pop();

        Node *frontNode = top.first;
        int hd = top.second;

        topNode[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    return topNode;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    unordered_map<int, int> ans = BottomView(root);

    for (auto i : ans)
    {
        cout << i.second << endl;
    }
}