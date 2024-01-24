// Delete m nodes after n Node
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
Node* takeinput(){
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;
    while(data!=-1){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* deleteMnodes(Node* head,int m,int n){
    if(head==NULL)
    return head;
    Node* temp=head;
    while(temp){
        int count=0;
        while(temp&&count<m-1){
            temp=temp->next;
            count++;
        }
        if(temp==NULL)
        return head;
        Node* t=temp->next;
        count=0;
        while(t&&count<n){
            Node* temp1=t;
            t=t->next;
            delete temp1;
            count++;
        }
        temp->next=t;
        temp=t;
    }
    return head;
}
int main(){
    Node* head=takeinput();
    int m,n;
    cin>>m>>n;
    head=deleteMnodes(head,m,n);
    print(head);
    return 0;
}
