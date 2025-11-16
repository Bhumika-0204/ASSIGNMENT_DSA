#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> smallestOnLeft(vector<int>& arr, int n) {
        set<int> s;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            auto it = s.lower_bound(arr[i]);  

            if (it == s.begin()) 
                ans.push_back(-1);
            else {
                it--;
                ans.push_back(*it);
            }

            s.insert(arr[i]);
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    vector<int> ans = obj.smallestOnLeft(arr, n);

    cout << "Smallest on left: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
