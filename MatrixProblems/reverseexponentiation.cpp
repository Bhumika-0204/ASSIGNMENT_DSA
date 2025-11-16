#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive power function
    long long power(long long x, long long y) {
        if (y == 0)
            return 1;
        long long half = power(x, y / 2);
        long long result = (half * half);
        if (y % 2)
            result *= x;
        return result;
    }

    int reverseExponentiation(int n) {
        int rev = 0, temp = n;
        while (temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        return power(n, rev);
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    cout << "Result: " << obj.reverseExponentiation(n);
    return 0;
}
