#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    bool isComplete(vector<int>& arr) {
        int n = arr.size();
        queue<int> q;

        int i = 0;
        bool nullFound = false;

        while (i < n) {
            if (arr[i] == -1) {
                nullFound = true;
            }
            else {
                if (nullFound) return false; // NULL ke baad non-null → not complete
            }
            i++;
        }
        return true;
    }

    bool isHeapProperty(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i <= (n - 2) / 2; i++) {
            
            if (arr[i] == -1) return false; 

            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[left] != -1 && arr[i] < arr[left])
                return false;

            if (right < n && arr[right] != -1 && arr[i] < arr[right])
                return false;
        }
        return true;
    }

    bool isHeap(vector<int>& arr) {
        return isComplete(arr) && isHeapProperty(arr);
    }
};

int main() {
    int n;
    cout << "Enter number of nodes in array (level order): ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter tree in level-order (-1 for NULL): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    SolutionSTL sol;

    if (sol.isHeap(arr))
        cout << "Given Binary Tree IS a Max-Heap\n";
    else
        cout << "Given Binary Tree is NOT a Max-Heap\n";

    return 0;
}
