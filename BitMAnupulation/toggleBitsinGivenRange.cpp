#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int toggleBits(int n, int l, int r) {
        int len = r - l + 1;

        // Mask of len bits set to 1
        int mask = ((1 << len) - 1) << (l - 1);

        return n ^ mask; // XOR toggles bits
    }
};

int main() {
    int n, l, r;
    cout << "Enter number n: ";
    cin >> n;

    cout << "Enter l (starting bit): ";
    cin >> l;

    cout << "Enter r (ending bit): ";
    cin >> r;

    Solution sol;
    cout << "Result after toggling bits = "
         << sol.toggleBits(n, l, r) << endl;

    return 0;
}
