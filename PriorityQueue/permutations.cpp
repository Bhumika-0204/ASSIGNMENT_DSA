#include <iostream>
#include <vector>
using namespace std;

class PermutationSTL {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> used;

    void backtrack(vector<int>& nums) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums);
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);
        backtrack(nums);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    PermutationSTL obj;
    vector<vector<int>> res = obj.permute(nums);

    cout << "All permutations:\n";
    for (auto &v : res) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }

    return 0;
}
