#include<iostream>
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


Node* MergeTwoSortedLinkedlist(Node* l1, Node* l2){

    if(l1==NULL){
        return l2;
    }

    if(l2==NULL){
        return l1;
    }

    if(l1!=NULL && l1->data > l2->data){
      swap(l1,l2);

    }

    Node* res=l1;

    while(l1!=NULL && l2!=NULL){

        Node* temp=NULL;

        while(l1!=NULL && l1->data <=l2->data){
            temp=l1;
            l1=l1->next;
        }

        temp->next=l2;
        swap(l1,l2);
    }

    return res;


}