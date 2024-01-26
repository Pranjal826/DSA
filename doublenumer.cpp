//  Double a number represented as linked list
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
void sol(Node*head,int &carry){
    if(!head)return;
    sol(head->next,carry);
    int prod=head->data*2+carry;
    head->data=prod%10;
    carry=prod/10;
}
Node*doubleIt(Node*head){
    int carry=0;
    sol(head,carry);
    if(carry){
        Node*carrNode=new Node(carry);
        carrNode->next=head;
        head=carrNode;
    }
    return head;
}
void print(Node*head){
    while(head){
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
    head=doubleIt(head);
    print(head);
    return 0;
}
