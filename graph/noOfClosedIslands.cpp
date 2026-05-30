#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>>& grid, int n, int m, bool &isClosed) {
    if (i < 0 || j < 0 || i >= n || j >= m) {
        isClosed = false;
        return;
    }

    if (grid[i][j] == 1) return;

    grid[i][j] = 1;

    dfs(i+1, j, grid, n, m, isClosed);
    dfs(i-1, j, grid, n, m, isClosed);
    dfs(i, j+1, grid, n, m, isClosed);
    dfs(i, j-1, grid, n, m, isClosed);
}

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter grid (0 land, 1 water):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int closed = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                bool isClosed = true;
                dfs(i, j, grid, n, m, isClosed);
                if (isClosed) closed++;
            }
        }
    }

    cout << closed;
}
