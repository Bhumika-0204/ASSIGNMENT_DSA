#include <iostream>
#include <stack>
using namespace std;

class MyQueueSTL {
public:
    stack<int> s1, s2;

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    MyQueueSTL qu;

    cout << "\nCommands:\n";
    cout << "1 x : push(x)\n";
    cout << "2   : pop()\n";
    cout << "3   : peek()\n";
    cout << "4   : empty()\n\n";

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x; cin >> x;
            qu.push(x);
        }
        else if (type == 2) {
            cout << qu.pop() << endl;
        }
        else if (type == 3) {
            cout << qu.peek() << endl;
        }
        else if (type == 4) {
            cout << (qu.empty() ? "true" : "false") << endl;
        }
    }
}
