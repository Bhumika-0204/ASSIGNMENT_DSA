
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;

        while (srow <= erow && scol <= ecol) {
            // top
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(matrix[srow][j]);
            }
            // right
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }
            // bottom
            for (int j = ecol - 1; j >= scol; j--) {
                if (srow == erow) break;
                ans.push_back(matrix[erow][j]);
            }
            // left
            for (int i = erow - 1; i >= srow + 1; i--) {
                if (scol == ecol) break;
                ans.push_back(matrix[i][scol]);
            }

            srow++;
            erow--;
            scol++;
            ecol--;
        }
        return ans;
    }
};

int main() {
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Print input matrix
    cout << "\nInput Matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Perform spiral order traversal
    Solution obj;
    vector<int> result = obj.spiralOrder(matrix);

    // Print result
    cout << "\nSpiral Order Traversal:\n";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
