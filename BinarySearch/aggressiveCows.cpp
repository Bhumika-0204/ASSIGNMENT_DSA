#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPlace(vector<int>& stalls, int k, int dist) {
        int count = 1;
        int lastPos = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= dist) {
                count++;
                lastPos = stalls[i];
                if (count >= k) return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int left = 1;
        int right = stalls.back() - stalls.front();
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canPlace(stalls, k, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    int n, k;
    cout << "Enter number of stalls: ";
    cin >> n;

    vector<int> stalls(n);
    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++) cin >> stalls[i];

    cout << "Enter number of cows: ";
    cin >> k;

    Solution obj;
    cout << "Maximum Minimum Distance: " << obj.aggressiveCows(stalls, k);
}
