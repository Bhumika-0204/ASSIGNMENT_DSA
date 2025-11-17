#include <iostream>
#include <vector>
using namespace std;

class SolutionSTL {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (int bit = 0; bit < 32; bit++) {
            int count = 0;
            for (int num : nums) {
                if (num & (1 << bit))
                    count++;
            }
            if (count % 3 != 0)
                result |= (1 << bit);
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    SolutionSTL obj;
    int ans = obj.singleNumber(nums);

    cout << "The single number is: " << ans << endl;
    return 0;
}
