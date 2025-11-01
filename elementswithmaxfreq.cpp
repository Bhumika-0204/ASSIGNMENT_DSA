#include <iostream>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(int arr[], int n) {
        int freq[1000]; // Assuming max 1000 elements
        int unique[1000];
        int u = 0;

        // Initialize freq
        for (int i = 0; i < n; i++) freq[i] = 0;

        // Count frequency manually
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 0; j < u; j++) {
                if (arr[i] == unique[j]) {
                    freq[j]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                unique[u] = arr[i];
                freq[u] = 1;
                u++;
            }
        }

        // Find max frequency
        int maxFreq = 0;
        for (int i = 0; i < u; i++)
            if (freq[i] > maxFreq)
                maxFreq = freq[i];

        // Sum all elements with max frequency
        int count = 0;
        for (int i = 0; i < u; i++)
            if (freq[i] == maxFreq)
                count += freq[i];

        return count;
    }
};

int main() {
    int n;
    cin >> n;
    int arr[1000];
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << obj.maxFrequencyElements(arr, n);
    return 0;
}
