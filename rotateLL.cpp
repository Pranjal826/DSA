// Rotate linked list
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
int getlen(Node*head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}
Node*rotateright(Node*head,int k){
    if(!head)
    return 0;
    int len=getlen(head);
    int actual=k%len;
    if(actual==0)
    return head;
    int newlastPos=len-actual-1;
    Node*newlast=head;
    while(newlastPos--){
        newlast=newlast->next;
    }
    Node*newhead=newlast->next;
    newlast->next=NULL;
    Node*it=newhead;
    while(it->next!=NULL){
        it=it->next;
    }
    it->next=head;
    return newhead;
}

void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=new Node(7);
    head->next->next->next->next->next->next->next=new Node(8);
    head->next->next->next->next->next->next->next->next=new Node(9);
    head->next->next->next->next->next->next->next->next->next=new Node(10);
    head=rotateright(head,3);
    print(head);
    return 0;
}
