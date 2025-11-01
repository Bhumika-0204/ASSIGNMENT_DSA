#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int nums[], int n) {
        // Sort first since array might not be sorted
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j]) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }

        if (n == 0) return 0;
        int index = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

int main() {
    int n;
    cout << "Enter size of an array: ";
    cin >> n;
    int nums[n];
    cout << "Enter elements of an array: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution obj;
    int res = obj.removeDuplicates(nums, n);

    cout << "Number of unique elements: " << res << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < res; i++) cout << nums[i] << " ";
    return 0;
}
