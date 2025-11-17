#include <iostream>
using namespace std;

class Solution {
public:
    void twoSum(int nums[], int n, int target, int res[]) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    res[0] = i;
                    res[1] = j;
                    return;
                }
            }
        }
        res[0] = res[1] = -1;
    }
};

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    int nums[10000];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    int res[2];
    obj.twoSum(nums, n, target, res);

    cout << "Result indices: " << res[0] << " " << res[1] << endl;
}
