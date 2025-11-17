#include <iostream>
#include <vector>
using namespace std;

class SolutionSTL {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++)
            if (isPrime[i]) count++;

        return count;
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    SolutionSTL obj;
    int ans = obj.countPrimes(n);

    cout << "Number of primes less than " << n << " is: " << ans << endl;

    return 0;
}
