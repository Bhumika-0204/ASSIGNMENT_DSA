#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int oldColor, int newColor, vector<vector<int>>& img, int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m || img[i][j] != oldColor)
        return;

    img[i][j] = newColor;

    dfs(i+1, j, oldColor, newColor, img, n, m);
    dfs(i-1, j, oldColor, newColor, img, n, m);
    dfs(i, j+1, oldColor, newColor, img, n, m);
    dfs(i, j-1, oldColor, newColor, img, n, m);
}

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> img(n, vector<int>(m));
    cout << "Enter image:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> img[i][j];

    int sr, sc, newColor;
    cout << "Enter sr, sc, newColor: ";
    cin >> sr >> sc >> newColor;

    int oldColor = img[sr][sc];
    if (oldColor != newColor)
        dfs(sr, sc, oldColor, newColor, img, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << img[i][j] << " ";
        cout << endl;
    }
}
