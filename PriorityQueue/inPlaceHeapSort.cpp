#include <bits/stdc++.h>
using namespace std;

class HeapSort {
public:

    // Down-heapify (bubble-down)
    void heapify(vector<long long>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);  // bubble down
        }
    }

    // Build max-heap (Bottom-up O(n))
    void buildMaxHeap(vector<long long>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    // In-place Heap Sort
    void heapSort(vector<long long>& arr) {
        int n = arr.size();

        // Step 1: build max-heap
        buildMaxHeap(arr);

        // Step 2: remove max and shrink heap
        for (int i = n - 1; i >= 1; i--) {
            swap(arr[0], arr[i]);     // move max to end
            heapify(arr, i, 0);       // fix heap of size i
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

    HeapSort hs;
    hs.heapSort(arr);

    cout << "Sorted array (ascending): ";
    for (long long x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

