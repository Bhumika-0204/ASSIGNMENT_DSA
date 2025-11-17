#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkKthBit(int n, int k) {
        return (n & (1 << k)) != 0;
    }
};

int main() {
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    bool ans = sol.checkKthBit(n, k);

    if (ans)
        cout << "K-th bit is SET (true)\n";
    else
        cout << "K-th bit is NOT set (false)\n";

    return 0;
}
