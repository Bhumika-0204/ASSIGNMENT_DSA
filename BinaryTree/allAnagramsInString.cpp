#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.size() > s.size()) return res;

        vector<int> freqP(26, 0), freqS(26, 0);

        for (char c : p) freqP[c - 'a']++;

        int k = p.size();

        for (int i = 0; i < s.size(); i++) {
            freqS[s[i] - 'a']++;

            if (i >= k)
                freqS[s[i - k] - 'a']--;

            if (freqS == freqP)
                res.push_back(i - k + 1);
        }
        return res;
    }
};

int main() {
    string s, p;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string p: ";
    cin >> p;

    SolutionSTL sol;
    vector<int> ans = sol.findAnagrams(s, p);

    cout << "Anagram Start Indices: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
