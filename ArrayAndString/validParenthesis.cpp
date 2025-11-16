#include<iostream>
#include<stack>
using namespace std;
bool isBalanced(string s){
    if(s.length()%2!=0) return false;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
        else{
            if(st.isEmpty()) return false;
            else if(st.top()=='('&&s[i]==')' )||
                 ( st.top()=='[' && s[i]==']')    ||
                (st.top()=='{' && s[i]=='}'){
                    st.pop();
            } 
            else return false;
        }
    }
    return st.size()==0;
}
int main(){
    string s;
    cout<<"Enter string (parenthesis)";
    cin>>s;
    isValid(s);
    return 0;
}