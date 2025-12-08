#include <iostream>
#include <vector>
using namespace std;

class SolutionSTL {
public:
    int mod = 1337;

    int modPow(int a, int k) {
        a %= mod;
        int result = 1;
        while (k > 0) {
            if (k & 1) result = (result * a) % mod;
            a = (a * a) % mod;
            k >>= 1;
        }
        return result;
    }

    int superPow(int a, vector<int>& b) {
        int result = 1;
        for (int digit : b) {
            result = modPow(result, 10) * modPow(a, digit) % mod;
        }
        return result;
    }
};

int main() {
    int a, n;
    cout << "Enter a: ";
    cin >> a;

    cout << "Enter size of exponent array b: ";
    cin >> n;

    vector<int> b(n);
    cout << "Enter digits of b: ";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    SolutionSTL obj;
    cout << "Result = " << obj.superPow(a, b) << endl;

    return 0;
}
