#include <iostream>
using namespace std;

class SolutionNoSTL {
public:
    int singleNumber(int arr[], int n) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            x ^= arr[i];
        }
        return x;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SolutionNoSTL obj;
    int ans = obj.singleNumber(arr, n);

    cout << "The single number is: " << ans << endl;

    delete[] arr;
    return 0;
}
