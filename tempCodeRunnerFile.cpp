// Intersection of two linked list
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

Node*getIntersection(Node*head1,Node*head2){
    Node*a=head1;
    Node*b=head2;
    while(a->next&&b->next){
        if(a==b){
            return a;
        }
        a=a->next;
        b=b->next;
    }
    if(a->next==0){
        int blen=0;
        while(b->next){
            blen++;
            b=b->next;
        }
        while(blen--){
            head2=head2->next;
        }
    }
    else{
        int alen=0;
        while(a->next){
            alen++;
            a=a->next;
        }
        while(alen--){
            head1=head1->next;
        }
    }
    while(head1!=head2){
        head1=head1->next;
        head2=head2->next;
    }
    return head1;
    
}
int main() {
    int n,m;
    cin>>n>>m;
    Node*head1=NULL;
    Node*head2=NULL;
    Node*tail1=NULL;
    Node*tail2=NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node*temp=new Node(x);
        if(head1==NULL){
            head1=temp;
            tail1=temp;
        }
        else{
            tail1->next=temp;
            tail1=temp;
        }
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        Node*temp=new Node(x);
        if(head2==NULL){
            head2=temp;
            tail2=temp;
        }
        else{
            tail2->next=temp;
            tail2=temp;
        }
    }
    Node*ans=getIntersection(head1,head2);
    cout<<ans->data;
    return 0;
}
