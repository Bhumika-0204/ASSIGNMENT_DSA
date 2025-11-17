#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> mp;

        for (char c : s) mp[c]++;
        for (char c : t) mp[c]--;

        for (auto &p : mp)
            if (p.second != 0) return false;

        return true;
    }
};

int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    SolutionSTL sol;

    if (sol.isAnagram(s, t))
        cout << "Strings are Anagrams\n";
    else
        cout << "Strings are NOT Anagrams\n";

    return 0;
}
