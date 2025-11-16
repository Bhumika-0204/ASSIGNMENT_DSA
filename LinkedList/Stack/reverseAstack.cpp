#include<bits/stdc++.h>
using namespace std;

// Correct print function
void print(stack<int>& st) {
    stack<int> temp;

    // Move st → temp
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    cout << "Stack (top to bottom): ";

    // Print and restore
    while (!temp.empty()) {
        cout << temp.top() << " ";
        st.push(temp.top());
        temp.pop();
    }

    cout << endl;
}
void pushAtAnyIndex(stack<int>st,int idx,int  val)
void pushAtBottom(stack<int>&st,int val){
    stack<int> temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    st.push( val);
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }


}

int main() {
    stack<int> st;
    stack<int> gt;
    stack<int> rt;
    
    int n;
    cout << "Enter capacity of a stack: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter elements of a stack:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        st.push(arr[i]);
    }

    cout << "\nOriginal Stack:\n";
    print(st);

    // empty st → rt
    while (!st.empty()) {
        rt.push(st.top());
        st.pop();
    }

    // empty rt → gt
    while (!rt.empty()) {
        gt.push(rt.top());
        rt.pop();
    }

    // empty gt → st
    while (!gt.empty()) {
        st.push(gt.top());
        gt.pop();
    }

    cout << "\nStack After Passing Through 2 Extra Stacks:\n";
    print(st);
    pushAtBottom(st,200);
    print(st);

    return 0;
}
