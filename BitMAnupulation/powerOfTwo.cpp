#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    SolutionSTL sol;
    if (sol.isPowerOfTwo(n))
        cout << n << " is a power of two\n";
    else
        cout << n << " is NOT a power of two\n";

    return 0;
}
