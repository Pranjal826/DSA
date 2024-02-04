// Longest valid Parenthesis
#include<iostream>
#include<stack>
using namespace std;
int longestValidParenthesis(string s){
    stack<int>st;
    st.push(-1);
    int res = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(i);
        }
        else{
            st.pop();
            if(!st.empty()){
                res = max(res,i-st.top());
            }
            else{
                st.push(i);
            }
        }
    }
    return res;
}
int main(){
    string s;
    cin>>s;
    cout<<longestValidParenthesis(s);
    return 0;
}
