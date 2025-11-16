#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;        // normal stack
    stack<int> minSt;     // minimum stack

    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top())
            minSt.push(x);
        else
            minSt.push(minSt.top());
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
            minSt.pop();
        }
    }

    int top() {
        if (!st.empty()) return st.top();
        return -1;
    }

    int getMin() {
        if (!minSt.empty()) return minSt.top();
        return -1;
    }
};

int main() {
    MinStack obj;
    int q;
    cout << "Enter number of operations: ";
    cin >> q;

    while(q--) {
        string op;
        cin >> op;

        if (op == "push") {
            int x; cin >> x;
            obj.push(x);
        } 
        else if (op == "pop") obj.pop();
        else if (op == "top") cout << obj.top() << endl;
        else if (op == "getMin") cout << obj.getMin() << endl;
    }

    return 0;
}
