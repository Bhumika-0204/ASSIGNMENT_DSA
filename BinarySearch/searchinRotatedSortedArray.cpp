#include <iostream>
#include <vector>
using namespace std;

class SolutionSTL {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            // Left part sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            // Right part sorted
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter rotated sorted array: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter target: ";
    cin >> target;

    SolutionSTL obj;
    cout << "Index: " << obj.search(nums, target);
}
