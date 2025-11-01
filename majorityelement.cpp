#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == candidate)
                count++;
            else
                count--;
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
        return candidate;
    }
};

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution obj;
    int ans = obj.majorityElement(nums);

    cout << "Majority Element is: " << ans << endl;
    return 0;
}
