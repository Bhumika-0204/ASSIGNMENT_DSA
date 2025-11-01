#include <iostream>
using namespace std;

class Solution {
public:
    int arraySum(int arr[], int n) {
        return sumHelper(arr, n);
    }

private:
    int sumHelper(int arr[], int n) {
        if (n == 0) return 0;
        return arr[n - 1] + sumHelper(arr, n - 1);
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << "Sum of array elements: " << obj.arraySum(arr, n);
    return 0;
}
