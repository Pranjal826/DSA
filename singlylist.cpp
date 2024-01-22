#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(){
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtHead(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;;
    }
    else{
        Node*newNode=new Node(data);
        newNode->next=head;
        head=newNode;
    }
}

void insertAtTail(Node*&head,Node*&tail,int data){
    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        Node*newNode=new Node(data);
        tail->next=newNode;
        tail=newNode;
    }
}
int findLength(Node*&head){
    Node*temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void insertAtPos(Node*&head,Node*&tail,int data,int pos){
    int len=findLength(head);
  if(pos==1){
    insertAtHead(head,tail,data);
    return;
  }
  else if(pos>len){
    insertAtTail(head,tail,data);
    return;
  }
  else{
    Node*newNode=new Node(data);
    Node*prev=NULL;
    Node*curr=head;
    while(pos!=1){
      pos--;
      prev=curr;
      curr=curr->next;
    }
    newNode->next=curr;
    prev->next=newNode;
  }
}
void deleteAtBeg(Node* &head,Node* &tail){
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

void deleteAtTail(Node* &head,Node* &tail){
    if(head==NULL){
        return;
    }
 if(head==tail){
       Node*temp=head;
       delete temp;
         head=NULL;
            tail=NULL;
            return;
    }
    Node*prev=head;
    while(prev->next!=tail){
        prev=prev->next;
    }
    prev->next=NULL;
    delete tail;
    tail=prev;
}

void reverseList(Node*& head, Node*& tail) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    tail = head;
    head = prev;
}
void print(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);

    print(head);
    cout << endl;
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 70);
    insertAtTail(head, tail, 80);
    print(head);
    cout << endl;

    insertAtPos(head, tail, 10, 3);
    insertAtPos(head, tail, 20, 4);
    print(head);

    deleteAtBeg(head, tail);
    print(head);
    deleteAtTail(head, tail);
    print(head);
    reverseList(head, tail);
    print(head);

    return 0;
}
