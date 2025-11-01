#include <iostream>
using namespace std;

class Solution {
public:
    void towerOfHanoi(int n, char source, char destination, char auxiliary) {
        if (n == 1) {
            cout << "Move disk 1 from " << source << " to " << destination << endl;
            return;
        }

        towerOfHanoi(n - 1, source, auxiliary, destination);
        cout << "Move disk " << n << " from " << source << " to " << destination << endl;
        towerOfHanoi(n - 1, auxiliary, destination, source);
    }
};

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    Solution obj;
    obj.towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}
