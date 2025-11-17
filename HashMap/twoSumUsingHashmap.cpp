#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value → index

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int target;
    cout << "Enter target: ";
    cin >> target;

    SolutionSTL sol;
    vector<int> ans = sol.twoSum(nums, target);

    if (ans.empty()) {
        cout << "No two sum solution.\n";
    } else {
        cout << "Indices: " << ans[0] << " " << ans[1] << "\n";
    }

    return 0;
}
