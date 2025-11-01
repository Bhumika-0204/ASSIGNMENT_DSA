#include <iostream>
using namespace std;

class Solution {
public:
    int fibonacci(int n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
};

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    Solution obj;
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << obj.fibonacci(i) << " ";
    }
    cout << endl;
    return 0;
}
