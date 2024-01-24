//Merge two sorted list
//Given a sorted linked list A and B, merge the two lists into one sorted linked list
//and return it.
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
Node* merge(Node* head1,Node* head2){
if(head1==NULL)
return head2;
if(head2==NULL)
return head1;
Node*ans=new Node(-1);
Node*ptr=ans;
while(head1&&head2){
    if(head1->data<=head2->data){
        ptr->next=head1;
        ptr=head1;
        head1=head1->next;
    }
    else{
        ptr->next=head2;
        ptr=head2;
        head2=head2->next;

    }

}
while(head1){
    ptr->next=head1;
    ptr=head1;
    head1=head1->next;
}
while(head2){
    ptr->next=head2;
    ptr=head2;
    head2=head2->next;
}
return ans->next;
}
int main(){
    Node* head1=takeinput();
    Node* head2=takeinput();
    Node* head=merge(head1,head2);
    print(head);
    return 0;
}