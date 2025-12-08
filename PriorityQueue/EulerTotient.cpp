#include <iostream>
using namespace std;

class TotientSTL {
public:
    int phi(int n) {
        int result = n;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        }

        if (n > 1)
            result -= result / n;

        return result;
    }
};

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    TotientSTL obj;
    cout << "Phi(" << n << ") = " << obj.phi(n) << endl;

    return 0;
}
