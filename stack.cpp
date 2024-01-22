#include<iostream>
#include<stack>
using namespace std;
class  Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
arr=new int[size];
this->size=size;
this->top=-1;
    }
    void push(int data){
        if(top==size-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        else{
  top++;
        arr[top]=data;
        }
      
    }
    void pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return;
        }
        else{
        top--;
        }
    }
    bool empty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
     int gettop(){
        if(top==-1){
           cout<<"Stack empty"<<endl;
        }
        return arr[top];
     }
     int getsize(){
            return top+1;
     }
   
     void print(){
            for(int i=0;i<=top;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
     }
int sol(stack<int>& st, int pos) {
    if (pos == 1) {
        return st.top();
    }

    int temp = st.top();
    st.pop();
    int result = sol(st, pos - 1);
    st.push(temp);

    return result;
}
int getmiddleelement(stack<int>& st) {
    int size = st.size();
    int pos = 0;
    
    if (st.empty()) {
        cout << "Stack empty" << endl;
        return -1;
    } else {
        if (size % 2 == 0) {
            pos = size / 2;
        } else {
            pos = (size + 1) / 2;
        }
    }

    return sol(st, pos);
}
};
int main(){
    Stack s(5);
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.print();
    // s.pop();
    // s.print();
    // cout<<s.gettop()<<endl;
    // cout<<s.getsize()<<endl;
    // cout<<s.empty()<<endl;
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<s.getmiddleelement(st)<<endl;
    return 0;

}