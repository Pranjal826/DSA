#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(){
        this->prev=NULL;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};
void insertAtBeg(Node*&head,Node*&tail,int data){
    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        Node*newNode=new Node(data);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}
void insertAtEnd(Node*&head,Node*&tail,int data){
    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        Node*newNode=new Node(data);
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}
void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
void deleteAtBeg(Node*&head,Node*&tail){
    if(head==NULL){
        return;
    }
    else if(head->next==NULL){
        delete head;
        head=NULL;
        tail=NULL;
    }
    else{
        Node*temp=head;
        head=head->next;
        delete temp;
    }
}
int main(){
    Node*head=NULL;
    Node*tail=NULL;
    insertAtBeg(head,tail,10);
    insertAtBeg(head,tail,20);
    insertAtBeg(head,tail,30);
    insertAtBeg(head,tail,40);
    insertAtBeg(head,tail,50);
    insertAtBeg(head,tail,60);
// insertAtEnd(head,tail,70);
    print(head);
    cout<<endl;

    insertAtEnd(head,tail,70);
    print(head);
    cout<<endl;
    deleteAtBeg(head,tail);
    print(head);

    return 0;
}
