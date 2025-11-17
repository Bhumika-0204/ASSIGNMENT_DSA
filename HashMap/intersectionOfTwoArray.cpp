#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> mp;
        vector<int> result;

        // put nums1 elements in map
        for (int x : nums1) mp[x] = true;

        // check nums2 elements
        unordered_map<int, bool> added;
        for (int x : nums2) {
            if (mp.find(x) != mp.end() && !added[x]) {
                result.push_back(x);
                added[x] = true; // to avoid duplicates
            }
        }

        return result;
    }
};

int main() {
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;
    vector<int> nums1(n);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; i++) cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> m;
    vector<int> nums2(m);
    cout << "Enter elements of second array: ";
    for (int i = 0; i < m; i++) cin >> nums2[i];

    SolutionSTL sol;
    vector<int> ans = sol.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
