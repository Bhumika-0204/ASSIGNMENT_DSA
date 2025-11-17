#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (int x : nums)
            pq.push(x);

        while (--k > 0)
            pq.pop();

        return pq.top();
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int k;
    cout << "Enter K: ";
    cin >> k;

    SolutionSTL sol;
    cout << "Kth Largest Element = " << sol.findKthLargest(nums, k) << endl;

    return 0;
}
