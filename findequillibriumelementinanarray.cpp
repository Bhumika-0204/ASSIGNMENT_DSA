#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(const vector<int>& nums) {
        long long total = 0;
        for (int x : nums) total += x;
        long long left = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (left == total - left - nums[i]) return i;
            left += nums[i];
        }
        return -1;
    }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    Solution s;
    cout << s.pivotIndex(nums) << '\n';
    return 0;
}
