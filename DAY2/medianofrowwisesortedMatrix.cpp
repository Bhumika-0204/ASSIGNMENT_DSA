#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>> &matrix) {
    int r = matrix.size(), c = matrix[0].size();
    int minVal = matrix[0][0], maxVal = matrix[0][c-1];

    for (int i = 1; i < r; i++) {
        minVal = min(minVal, matrix[i][0]);
        maxVal = max(maxVal, matrix[i][c - 1]);
    }

    int desired = (r * c + 1) / 2;

    while (minVal < maxVal) {
        int mid = minVal + (maxVal - minVal) / 2;
        int place = 0;

        for (int i = 0; i < r; i++) {
            place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (place < desired)
            minVal = mid + 1;
        else
            maxVal = mid;
    }
    return minVal;
}

int main() {
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    vector<vector<int>> mat(r, vector<int>(c));

    cout << "Enter matrix elements (each row sorted):\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Median of matrix = " << findMedian(mat) << endl;
    return 0;
}
