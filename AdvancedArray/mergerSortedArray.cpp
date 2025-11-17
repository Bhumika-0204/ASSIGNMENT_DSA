#include <iostream>
using namespace std;

class SolutionNoSTL {
public:
    void merge(int nums1[], int m, int nums2[], int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;

    int nums1[20000], nums2[20000];

    cout << "Enter nums1 (first " << m << " sorted elements): ";
    for (int i = 0; i < m; i++) cin >> nums1[i];

    // Fill remaining space with 0 (only placeholders)
    for (int i = m; i < m + n; i++) nums1[i] = 0;

    cout << "Enter nums2 (" << n << " sorted elements): ";
    for (int i = 0; i < n; i++) cin >> nums2[i];

    SolutionNoSTL obj;
    obj.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int i = 0; i < m + n; i++) cout << nums1[i] << " ";
}
