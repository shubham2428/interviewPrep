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

Node* middleEfficient(Node* &head){

    Node* slow=head;
    Node* fast=head;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;

}


Node* middle(Node* &head){

    Node* temp=head;
    int count=0;

    while(temp){
        count++;
        temp=temp->next;
    }


    for(int i =0;i<count/2;i++){
        head=head->next;
    }
    return head;

}