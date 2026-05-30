#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis, int n) {
    vis[node] = 1;
    for (int j = 0; j < n; j++) {
        if (isConnected[node][j] == 1 && !vis[j])
            dfs(j, isConnected, vis, n);
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));
    cout << "Enter matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> isConnected[i][j];

    vector<int> vis(n, 0);
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            provinces++;
            dfs(i, isConnected, vis, n);
        }
    }

    cout << provinces;
}
