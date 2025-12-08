#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, content = 0;
        while (i < (int)g.size() && j < (int)s.size()) {
            if (s[j] >= g[i]) {
                ++content;
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        return content;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> g(n), s(m);
    for (int i = 0; i < n; ++i) cin >> g[i];
    for (int j = 0; j < m; ++j) cin >> s[j];

    Solution sol;
    cout << sol.findContentChildren(g, s) << '\n';
    return 0;
}
