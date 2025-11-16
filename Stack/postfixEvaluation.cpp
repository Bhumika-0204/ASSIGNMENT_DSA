#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

class SolutionSTL {
public:
    bool isOperator(string &s) {
        return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^");
    }

    int applyOp(int a, int b, string &op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b;   // C++ already floors towards zero -> required
        if (op == "^") {
            int res = 1;
            for (int i = 0; i < b; i++) res *= a;
            return res;
        }
        return 0;
    }

    int evaluate(vector<string> &arr) {
        stack<int> st;

        for (string token : arr) {
            if (!isOperator(token)) {
                st.push(stoi(token));
            } else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(applyOp(a, b, token));
            }
        }
        return st.top();
    }
};

int main() {
    int n;
    cout << "Enter number of tokens: ";
    cin >> n;

    vector<string> arr(n);
    cout << "Enter tokens: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    SolutionSTL obj;
    cout << "Result: " << obj.evaluate(arr) << endl;

    return 0;
}
