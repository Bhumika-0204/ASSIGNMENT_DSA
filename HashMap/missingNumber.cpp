#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, bool> mp;

        for (int x : nums) mp[x] = true;

        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            if (mp.find(i) == mp.end()) return i;
        }
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    SolutionSTL sol;
    cout << "Missing Number = " << sol.missingNumber(nums) << endl;

    return 0;
}
