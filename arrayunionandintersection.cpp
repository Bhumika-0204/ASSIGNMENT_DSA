#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> result;

        for (int num : nums2) {
            if (s1.find(num) != s1.end())
                result.insert(num);
        }

        return vector<int>(result.begin(), result.end());
    }
};

int main() {
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; i++) cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; i++) cin >> nums2[i];

    Solution obj;
    vector<int> ans = obj.intersection(nums1, nums2);

    cout << "Intersection elements: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
