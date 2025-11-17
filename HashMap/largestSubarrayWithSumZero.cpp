#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> mp;  // prefix_sum -> first index
        int prefix = 0, maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefix += arr[i];

            if (prefix == 0) {
                maxLen = max(maxLen, i + 1);
            }

            if (mp.find(prefix) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefix]);
            } else {
                mp[prefix] = i;  // store first occurrence
            }
        }
        return maxLen;
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
    cout << "Largest subarray length with sum 0 = "
         << sol.maxLen(arr) << endl;

    return 0;
}
