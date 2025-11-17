#include <iostream>
using namespace std;

class SolutionNoSTL {
public:
    bool search(int nums[], int n, int target) {
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return true;

            // Handling duplicates
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // Left side sorted
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            // Right side sorted
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    int nums[10000];
    cout << "Enter rotated sorted array (with duplicates): ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter target: ";
    cin >> target;

    SolutionNoSTL obj;
    cout << (obj.search(nums, n, target) ? "Found" : "Not Found");
}
