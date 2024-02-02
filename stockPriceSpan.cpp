// Stock Price Span 
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int>st;
    int span[n];
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }
        span[i] = st.empty()?i+1:i-st.top();
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<span[i]<<" ";
    }
    return 0;
}