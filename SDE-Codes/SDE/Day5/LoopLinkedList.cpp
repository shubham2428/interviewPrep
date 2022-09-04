#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // constructor

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Time complexity is linear and space is also linear
bool loopCheckerandBreaker(Node *&head)
{
    unordered_set<Node *> mp;
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        if (mp.find(curr) != mp.end())
        {
            prev->next = NULL;
            return true;
        }
        mp.insert(curr);
        prev = curr;
        curr = curr->next;
    }
}

// time complexity is linear and space is constant;
bool loopCheckerandBreakerOptimal(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }

    if (slow != fast)
    {
        return false;
    }

    slow = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
    return true;
}