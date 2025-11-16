#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        vector<int> dp(n);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        }

        return dp[n - 1];
    }
};

int main() {
    int n;
    cout << "Enter number of houses: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter money in each house: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << "Maximum money that can be robbed: " << obj.rob(arr) << endl;

    return 0;
}
