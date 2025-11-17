#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> row(m, 0), col(n, 0);

        // Step 1: mark rows & cols which have 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Step 2: set rows to zero
        for (int i = 0; i < m; i++) {
            if (row[i]) {
                for (int j = 0; j < n; j++)
                    mat[i][j] = 0;
            }
        }

        // Step 3: set columns to zero
        for (int j = 0; j < n; j++) {
            if (col[j]) {
                for (int i = 0; i < m; i++)
                    mat[i][j] = 0;
            }
        }
    }
};

int main() {
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) 
            cin >> mat[i][j];

    SolutionSTL sol;
    sol.setZeroes(mat);

    cout << "Result Matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
