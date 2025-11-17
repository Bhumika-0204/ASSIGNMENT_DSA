#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    long long countSetBits(long long n) {
        if (n == 0) return 0;

        long long p = log2(n);
        long long pow2 = (1LL << p);

        long long bitsBefore = p * (pow2 >> 1);
        long long msbBits = n - pow2 + 1;
        long long rest = countSetBits(n - pow2);

        return bitsBefore + msbBits + rest;
    }
};

int main() {
    long long n;
    cout << "Enter n: ";
    cin >> n;

    SolutionSTL sol;
    cout << "Total set bits from 1 to " << n << " = "
         << sol.countSetBits(n) << endl;

    return 0;
}
