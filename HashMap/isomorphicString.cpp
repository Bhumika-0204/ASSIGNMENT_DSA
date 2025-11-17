#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mp1, mp2;

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];

            if (mp1.count(a)) {
                if (mp1[a] != b) return false;
            } else {
                mp1[a] = b;
            }

            if (mp2.count(b)) {
                if (mp2[b] != a) return false;
            } else {
                mp2[b] = a;
            }
        }
        return true;
    }
};

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    SolutionSTL sol;
    if (sol.isIsomorphic(s, t))
        cout << "Strings are Isomorphic\n";
    else
        cout << "Strings are NOT Isomorphic\n";

    return 0;
}
