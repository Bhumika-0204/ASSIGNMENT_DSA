#include <iostream>
#include <vector>
using namespace std;

class SolutionSTL {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_all = 0, xor_arr = 0;

        for (int i = 0; i <= n; i++) 
            xor_all ^= i;

        for (int x : nums) 
            xor_arr ^= x;

        return xor_all ^ xor_arr;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;  // array size is n but numbers will be from 0 to n

    vector<int> nums(n);
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    SolutionSTL obj;
    int ans = obj.missingNumber(nums);

    cout << "Missing number is: " << ans << endl;
    return 0;
}
