#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> Smallestonleft(int arr[], int n) {
        set<int> s;          // keeps previous elements in sorted order
        vector<int> ans;     // stores results

        for (int i = 0; i < n; i++) {
            auto it = s.lower_bound(arr[i]); // find first element >= arr[i]

            if (it == s.begin()) {
                ans.push_back(-1);           // no smaller element on left
            } else {
                it--;                        // move to the largest smaller element
                ans.push_back(*it);
            }

            s.insert(arr[i]);                // add current element to set
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    vector<int> ans = obj.Smallestonleft(arr, n);

    cout << "Largest smaller element on left: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
