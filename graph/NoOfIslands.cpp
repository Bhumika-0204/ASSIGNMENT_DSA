#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>>& grid, int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
        return;

    grid[i][j] = 0;

    dfs(i+1, j, grid, n, m);
    dfs(i-1, j, grid, n, m);
    dfs(i, j+1, grid, n, m);
    dfs(i, j-1, grid, n, m);
}

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter grid values (0/1):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int islands = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                islands++;
                dfs(i, j, grid, n, m);
            }
        }
    }

    cout << "Number of Islands = " << islands;
}
