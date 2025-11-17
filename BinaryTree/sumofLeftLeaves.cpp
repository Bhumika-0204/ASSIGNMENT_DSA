#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {

            // Remove out of window elements
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Start adding results after window forms
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }
        return result;
    }
};

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter window size k: ";
    cin >> k;

    SolutionSTL sol;
    vector<int> ans = sol.maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
