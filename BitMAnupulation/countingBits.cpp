#include <iostream>
using namespace std;

class Solution {
public:
    int* countBits(int n) {
        int* ans = new int[n + 1];
        ans[0] = 0;

        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution obj;
    int* result = obj.countBits(n);

    cout << "Number of set bits from 0 to " << n << " are:\n";
    for (int i = 0; i <= n; i++) {
        cout << "Count of set bits in " << i << " = " << result[i] << endl;
    }

    delete[] result;
    return 0;
}
