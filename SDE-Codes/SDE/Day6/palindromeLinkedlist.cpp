#include <iostream>
using namespace std;

class node
{
public:
    int num;
    node *next;
    node(int val)
    {
        num = val;
        next = NULL;
    }
};

void insertNode(node *head, int val)
{
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}

node *reverse(node *ptr)
{
    node *pre = NULL;
    node *next = NULL;

    while (ptr != NULL)
    {
        next = ptr->next;
        ptr->next = pre;

        pre = ptr;
        ptr = next;
    }

    return pre;
}

bool isPalindrome(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    // finding mid element using fast and slow pointer approach

    node *fast = head;
    node *slow = head;

    while (fast->next != NULL || fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // got middle element
    slow->next = reverse(slow->next);

    slow = slow->next;

    node *dummy = head;

    while (slow->next != NULL)
    {
        if (dummy->num != slow->num)
        {
            return false;
        }
        slow = slow->next;
        dummy = dummy->next;
    }

    return true;
}

int main()
{
    node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 2);
    insertNode(head, 1);
    isPalindrome(head) ? cout << "True" : cout << "False";
    return 0;
}