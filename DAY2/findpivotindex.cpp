#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0, leftSum = 0;
        for (int num : nums) totalSum += num;
        
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == totalSum - leftSum - nums[i])
                return i;
            leftSum += nums[i];
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

    Solution obj;
    int res = obj.pivotIndex(nums);
    cout << "Pivot Index: " << res << endl;
    return 0;
}
