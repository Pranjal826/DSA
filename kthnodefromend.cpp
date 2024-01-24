// Kth node from end 
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
void sol(Node*head,int &posfromTail,int &ans){
    if(head==0)
    return;
    sol(head->next,posfromTail,ans);
    if(posfromTail==0){
        ans=head->data;
    }
    posfromTail--;
}
int getNode(Node*head,int posfromTail){
    int ans=-1;
    sol(head,posfromTail,ans);
    return ans;
}
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
int main(){
    Node* head=takeinput();
    int posfromTail;
    cin>>posfromTail;
    cout<<getNode(head,posfromTail)<<endl;
    return 0;

}