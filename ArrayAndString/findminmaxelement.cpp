#include <iostream>
using namespace std;

class Solution {
public:
    int minimumDeletions(int nums[], int n) {
        int minIndex = 0, maxIndex = 0;

        // Find min and max indices manually
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex]) minIndex = i;
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }

        // Ensure minIndex < maxIndex for calculation simplicity
        if (minIndex > maxIndex) {
            int temp = minIndex;
            minIndex = maxIndex;
            maxIndex = temp;
        }

        // Calculate three possible ways:
        int leftOnly = maxIndex + 1;            // Remove from front only
        int rightOnly = n - minIndex;           // Remove from back only
        int bothSides = (minIndex + 1) + (n - maxIndex); // From both ends

        // Find minimum of the three
        int ans = leftOnly;
        if (rightOnly < ans) ans = rightOnly;
        if (bothSides < ans) ans = bothSides;

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int nums[1000];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution obj;
    cout << "Minimum deletions: " << obj.minimumDeletions(nums, n);
    return 0;
}
