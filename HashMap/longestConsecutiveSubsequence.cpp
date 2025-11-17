#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;

        for (int x : nums) mp[x] = true;

        int longest = 0;

        for (int x : nums) {
            // Check if x is starting point of a window
            if (mp.find(x - 1) == mp.end()) {

                int cur = x;
                int length = 1;

                // Expand sliding window: x, x+1, x+2...
                while (mp.find(cur + 1) != mp.end()) {
                    cur++;
                    length++;
                }

                longest = max(longest, length);
            }
        }
        return longest;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    SolutionSTL sol;
    cout << "Longest Consecutive Sequence Length = "
         << sol.longestConsecutive(arr) << endl;

    return 0;
}
