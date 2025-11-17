#include <iostream>
#include <vector>
using namespace std;

// Simulating API
int badVersion;

bool isBadVersion(int version) {
    return version >= badVersion;
}

class SolutionSTL {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, ans = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
                ans = mid;
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of versions: ";
    cin >> n;

    cout << "Enter first bad version: ";
    cin >> badVersion;

    SolutionSTL obj;
    cout << "First Bad Version: " << obj.firstBadVersion(n);
}
