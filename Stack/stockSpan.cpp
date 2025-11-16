#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st;

    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

int main() {
    int n;
    cout << "Enter number of prices: ";
    cin >> n;

    StockSpanner obj;

    cout << "Enter prices: ";
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        cout << obj.next(price) << " ";
    }
    cout << endl;

    return 0;
}
