#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // Sort the array for greedy pairing
        sort(nums.begin(), nums.end());

        int sum = 0;
        // Greedy: take every alternate element (minimum of each pair)
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

int main() {
    int n;
    cout << "Enter n (even number): ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    cout << "Maximum Sum = " << sol.arrayPairSum(nums) << "\n";
}
