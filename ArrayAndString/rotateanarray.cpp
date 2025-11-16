#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    void rotatearray(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        for (int i = 0; i < k; i++) {
            int last = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), last);
        }
    }
};

int main() {
    int n, k;
    cout << "Enter size of an array: ";
    cin >> n;
    cout << "Enter value of k: ";
    cin >> k;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    solution obj;
    obj.rotatearray(nums, k);

    cout << "Rotated Array: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
