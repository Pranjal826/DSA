// Next Smaller
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int>nextSmaller(int *arr,int size,vector<int>&ans){
    stack<int>st;
    st.push(-1);
    for(int i=size-1;i>=0;i--){
        int curr=arr[i];
        while(st.top()>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
    }
    return ans;
}
int main(){
    int arr[]={4,5,2,10,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    vector<int>ans(size);
    vector<int>res=nextSmaller(arr,size,ans);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
