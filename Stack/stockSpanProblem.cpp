#include <iostream>
using namespace std;

class MyStack {
public:
    int price[10000];
    int span[10000];
    int top;

    MyStack() { top = -1; }

    bool empty() { return top == -1; }

    void push(int p, int s) {
        top++;
        price[top] = p;
        span[top] = s;
    }

    void pop() {
        if (!empty()) top--;
    }

    int topPrice() { return price[top]; }
    int topSpan() { return span[top]; }
};

class StockSpannerNoSTL {
public:
    MyStack st;

    int next(int p) {
        int s = 1;

        while (!st.empty() && st.topPrice() <= p) {
            s += st.topSpan();
            st.pop();
        }

        st.push(p, s);
        return s;
    }
};

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    StockSpannerNoSTL obj;
    int prices[10000], result[10000];

    cout << "Enter prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
        result[i] = obj.next(prices[i]);
    }

    cout << "Stock spans: ";
    for (int i = 0; i < n; i++) cout << result[i] << " ";
    return 0;
}
