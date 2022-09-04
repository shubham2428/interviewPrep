#include<iostream>
using namespace std;

class Node{

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

void reverseLinkedlist(Node* &head){
    if(head==NULL){
        return;
    }

    Node* curr_next=NULL;
    Node* curr_prev=NULL;
    Node* curr=head;


    while(curr){
        curr_next=curr->next;
        curr->next=curr_prev;
        curr_prev=curr;
        curr=curr_next;

    }

    head=curr_prev;  // beacuse list will reverse , last element becomes head;

}