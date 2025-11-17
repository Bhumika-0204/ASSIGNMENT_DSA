#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; // char -> last index
        int l = 0, maxLen = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];

            if (mp.find(c) != mp.end() && mp[c] >= l) {
                l = mp[c] + 1; // slide window
            }

            mp[c] = r; // update last position
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    SolutionSTL sol;
    cout << "Longest substring length = "
         << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}
