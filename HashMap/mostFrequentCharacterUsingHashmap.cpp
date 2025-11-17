#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    char mostFrequentChar(string &s) {
        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        char ans = 'z';
        int maxFreq = 0;

        for (auto &p : mp) {
            int freq = p.second;
            char ch = p.first;

            if (freq > maxFreq || (freq == maxFreq && ch < ans)) {
                maxFreq = freq;
                ans = ch;
            }
        }
        return ans;
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    SolutionSTL sol;
    cout << "Most Frequent Character = " << sol.mostFrequentChar(s) << endl;

    return 0;
}
