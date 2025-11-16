#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    stack<int> temp;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.size()<<endl;
    cout<<"Elements of stack in reverse order";
    // while(st.size()>0){
    //     cout<<st.top()<<" ";
    //     st.pop();

    // }
    // we will use extra stack;
    while(st.size()>0){
        cout<<st.top()<<" ";
        st.pop();
        temp.push(st.top());

    }
    //putting elements back from temp to st
    while(temp.size()>0){
        cout<<st.top()<<" ";
        
        st.push(temp.top());
        temp.pop();

    }
    cout<<endl<<st.top();
    cout<<temp.top();
    
    return 0;
}