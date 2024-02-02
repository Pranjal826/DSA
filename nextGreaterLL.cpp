// Next Greater Element in linked list
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
vector<int>nextLarger(Node* head){
    vector<int>LL;
    while(head){
        LL.push_back(head->data);
        head = head->next;
    }
    stack<int>st;
    vector<int>res(LL.size());
    for(int i=0;i<LL.size();i++){
        while(!st.empty() && LL[st.top()]<LL[i]){
            res[st.top()] = LL[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        res[st.top()] = 0;
        st.pop();
    }
    return res;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    vector<int>res = nextLarger(head);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
