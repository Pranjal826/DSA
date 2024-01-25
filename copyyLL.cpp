// Copy LL with random pointer
#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;
    Node(int d){
        data=d;
        next=NULL;
        random=NULL;
    }
};
Node*helper(Node*head,unordered_map<Node*,Node*>&mp){
    if(head==NULL)
    return 0;
    Node*newNode=new Node(head->data);
    mp[head]=newNode;
    newNode->next=helper(head->next,mp);
    if(head->random){
        newNode->random=mp[head->random];
    }
    return newNode;
}
Node*copy(Node*head){
    unordered_map<Node*,Node*>mp;
    return helper(head,mp);
}
int main(){
    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->random=head->next->next;
    head->next->random=head;
    head->next->next->random=head->next->next->next->next;
    head->next->next->next->random=head->next->next->next->next;
    head->next->next->next->next->random=head->next;
    Node*newHead=copy(head);
    while(newHead){
        cout<<newHead->data<<" ";
        newHead=newHead->next;
    }
    return 0;
}
