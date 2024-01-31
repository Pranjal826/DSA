// Min Stack
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class MinStack
{
public:
vector<pair<int,int> >st;
    MinStack()
    {
    }
    void push(int val)
    {
       if(st.empty()){
        pair<int,int>p;
        p.first=val;
        p.second=val;
        st.push_back(p);
       }
       else{
        pair<int,int> p;
        p.first=val;
        p.second=val;
        int oldMin=st.back().second;
        p.second=min(oldMin,val);
        st.push_back(p);
       }
    }
    void pop()
    {
    st.pop_back();
    }
    int top()
    {
        pair<int,int>rigthPair=st.back();
        return rigthPair.first;
    }
    int getMin()
    {
    pair<int,int>rigthPair=st.back();
    return rigthPair.second;
    }
};
int main(){
MinStack* obj = new MinStack();
obj->push(10);
obj->push(20);
obj->push(30);
obj->push(40);
obj->push(50);
obj->push(60);
obj->push(70);
obj->push(80);
obj->push(90);
obj->push(100);
// 
obj->pop();
obj->pop();
// 
int param_3 = obj->top();
int param_4 = obj->getMin();
cout<<param_3<<endl;
cout<<param_4<<endl;
return 0;
}