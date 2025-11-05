#include <iostream>
using namespace std;

class Solution {
public:
    // Function to find row with maximum number of 1s
    void rowAndMaximumOnes(int **mat, int n, int m, int &maxRow, int &maxCount) {
        maxCount = 0;
        maxRow = 0;

        for (int i = 0; i < n; i++) {
            int count = countOnes(mat[i], m);
            if (count > maxCount) {
                maxCount = count;
                maxRow = i;
            }
        }
    }

private:
    // Helper function to count 1s in a row (manual loop)
    int countOnes(int arr[], int size) {
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == 1)
                cnt++;
        }
        return cnt;
    }
};

int main() {
    

    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    int **mat = new int*[n];
    for (int i = 0; i < n; i++) {
        mat[i] = new int[m];
    }

    cout << "Enter matrix elements (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    Solution sol;
    int maxRow, maxCount;
    sol.rowAndMaximumOnes(mat, n, m, maxRow, maxCount);

    cout << "Row index with maximum ones = " << maxRow
         << ", Count of ones = " << maxCount << "\n";

    // Free memory
    for (int i = 0; i < n; i++)
        delete[] mat[i];
    delete[] mat;

    return 0;
}
