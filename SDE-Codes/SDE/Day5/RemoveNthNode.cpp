#include<iostream>
using namespace std;


class Node
{

public:
    int data;
    Node *next;

    // constructor

    Node(){
        this->data=NULL;
        this->next=NULL;
    }

    //parameterised constructor

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


Node* removeNthFromEnd(Node* head, int n) {
        Node * start = new Node();
        start -> next = head;
        Node* fast = start;
        Node* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }