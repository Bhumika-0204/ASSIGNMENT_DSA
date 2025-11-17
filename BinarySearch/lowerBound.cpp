#include <iostream>
#include <vector>
using namespace std;

class SolutionSTL {
public:
    int lowerBound(vector<int> &arr, int target) {
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] >= target)
                return i;
        }
        return n;
    }
};

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of array (sorted): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter target: ";
    cin >> target;

    SolutionSTL obj;
    cout << "Lower Bound Index: " << obj.lowerBound(arr, target);
}
