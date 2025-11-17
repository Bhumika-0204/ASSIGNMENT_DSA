#include <iostream>
#include <vector>
using namespace std;

class SolutionSTL {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;

        vector<vector<int>> result;

        for (int mask = 0; mask < total; mask++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    SolutionSTL obj;
    vector<vector<int>> ans = obj.subsets(nums);

    cout << "\nAll subsets are:\n";
    for (auto &subset : ans) {
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    }
}
