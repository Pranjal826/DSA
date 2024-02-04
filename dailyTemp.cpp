// Daily Temperatures
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int>dailyTemperatures(vector<int>&tempeartures){
int n=tempeartures.size();
        vector<int>ans(n,0);
        stack<int>st;
         for(int i=n-1;i>=0;i--){
             if(st.empty()){
                 st.push(i);
                 ans[i]=0;
             }
             else{
                 while(!st.empty()&&tempeartures[i]>=tempeartures[st.top()]){
                     st.pop();
                 }
                 if(st.empty()){
                     ans[i]=0;
                 }
                 else{
                     ans[i]=st.top()-i;
                 }
                 st.push(i);
             }
         }
         return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>tempeartures(n);
    for(int i=0;i<n;i++){
        cin>>tempeartures[i];
    }
    vector<int>res = dailyTemperatures(tempeartures);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}