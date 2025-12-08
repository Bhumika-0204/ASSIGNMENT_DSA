#include <iostream>
#include <vector>
using namespace std;

class InclusionExclusionSTL {
public:
    long long fact(int n) {
        long long res = 1;
        for (int i = 2; i <= n; i++)
            res *= i;
        return res;
    }

    long long countGood() {
        long long total = fact(10);

        long long X = 2 * fact(9);  // first ≤ 1 → 2 options
        long long Y = 2 * fact(9);  // last ≥ 8 → 2 options
        long long XY = 2 * 2 * fact(8); // both restricted

        long long bad = X + Y - XY;

        return total - bad;
    }
};

int main() {
    InclusionExclusionSTL obj;

    cout << "Total valid permutations = " << obj.countGood() << endl;

    return 0;
}
