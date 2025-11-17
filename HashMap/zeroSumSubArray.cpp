#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    long long countZeroSumSubarrays(vector<int>& arr) {
        unordered_map<long long, long long> mp;
        long long prefix = 0, count = 0;

        mp[0] = 1;  // prefix sum 0 seen once

        for (int x : arr) {
            prefix += x;

            if (mp.find(prefix) != mp.end()) {
                count += mp[prefix];  // add previous occurrences
            }

            mp[prefix]++;  // store this prefix occurrence
        }

        return count;
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
    cout << "Total Zero-Sum Subarrays = "
         << sol.countZeroSumSubarrays(arr) << endl;

    return 0;
}
