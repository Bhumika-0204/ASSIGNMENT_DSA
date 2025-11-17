#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;   // prefixSum -> first index
        int prefix = 0, maxLen = 0;

        mp[0] = -1; // prefix 0 before starting

        for (int i = 0; i < nums.size(); i++) {
            prefix += (nums[i] == 0 ? -1 : 1);

            if (mp.find(prefix) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefix]);
            } else {
                mp[prefix] = i;
            }
        }

        return maxLen;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter only 0s and 1s: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    SolutionSTL sol;
    cout << "Longest subarray with equal 0s & 1s = "
         << sol.findMaxLength(nums) << endl;

    return 0;
}
