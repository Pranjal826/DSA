//  FLatten Linked list
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* bottom;
    Node(int d){
        data=d;
        next=NULL;
        bottom=NULL;
    }
};
Node*merge(Node*a,Node*b){
    if(a==NULL)return b;
    if(b==NULL)return a;
    Node*ans=0;
    if(a->data<b->data){
        ans=a;
        a->bottom=merge(a->bottom,b);
    }
    else{
        ans=b;
        b->bottom=merge(a,b->bottom);
    }
    return ans;
}
Node*flatten(Node*root){
    if(root==NULL||root->next==NULL)return root;
    return merge(root,flatten(root->next));
}
void print(Node*root){
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->bottom;
    }
    cout<<endl;
}
int main(){
    Node*root=new Node(5);
    root->next=new Node(10);
    root->next->next=new Node(19);
    root->next->next->next=new Node(28);
    root->next->next->next->next=new Node(7);
    root->next->next->next->next->next=new Node(8);
    root->next->next->next->next->next->next=new Node(30);
    root->next->bottom=new Node(20);
    root->next->next->bottom=new Node(22);
    root->next->next->next->bottom=new Node(35);
    root->next->next->next->next->bottom=new Node(40);
    root->next->next->next->next->next->bottom=new Node(45);
    root->next->next->next->next->next->next->bottom=new Node(50);
    root=flatten(root);
    print(root);
    return 0;
}