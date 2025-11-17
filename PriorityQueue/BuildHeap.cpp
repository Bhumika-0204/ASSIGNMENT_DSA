#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    void heapify(vector<long long>& arr, int n, int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void buildHeap(vector<long long>& arr) {
        int n = arr.size();
        for (int i = n/2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<long long> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    SolutionSTL sol;
    sol.buildHeap(arr);

    cout << "Heap Built Successfully\n";
    cout << "Heap array: ";
    for (long long x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
