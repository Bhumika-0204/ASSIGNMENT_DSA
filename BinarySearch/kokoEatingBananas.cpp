#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long hoursNeeded(vector<int>& piles, int k) {
        long long hours = 0;
        for (int p : piles)
            hours += (p + k - 1) / k;  // ceil
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hoursNeeded(piles, mid) <= h) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n, h;
    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);
    cout << "Enter pile values: ";
    for (int i = 0; i < n; i++) cin >> piles[i];

    cout << "Enter hours h: ";
    cin >> h;

    Solution obj;
    cout << "Minimum Speed: " << obj.minEatingSpeed(piles, h);
}
