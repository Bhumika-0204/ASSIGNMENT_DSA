#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SolutionSTL {
public:
    int upperBound(vector<int>& arr, int target) {
        auto it = upper_bound(arr.begin(), arr.end(), target);
        return it - arr.begin();
    }
};

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter target: ";
    cin >> target;

    SolutionSTL obj;
    cout << "Upper Bound Index: " << obj.upperBound(arr, target);
}
