#include<iostream>
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
};
int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.print();
    s.pop();
    s.print();
    cout<<s.gettop()<<endl;
    cout<<s.getsize()<<endl;
    cout<<s.empty()<<endl;
    return 0;

}