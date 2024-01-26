// Merge Nodes in between zeroes
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

Node*mergeNodes(Node*head){
    Node*slow=head,*fast=head->next,*newlastNode=0;
    int sum=0;
    while(fast){
        if(fast->data!=0){
            sum+=fast->data;
        }
        else{
            slow->data=sum;
            newlastNode=slow;
            slow=slow->next;
            sum=0;
        }
        fast=fast->next;

    }
    Node*tmp=newlastNode->next;
    newlastNode->next=0;
    while(tmp){
        Node*tmp2=tmp->next;
        delete tmp;
        tmp=tmp2;
    }
    return head;
}


int main(){
    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(0);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(0);
    head->next->next->next->next->next->next=new Node(7);
    head->next->next->next->next->next->next->next=new Node(0);
    head->next->next->next->next->next->next->next->next=new Node(9);
    head=mergeNodes(head);
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}