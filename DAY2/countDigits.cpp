#include <iostream>
#include <string>
using namespace std;

int evenlyDivides(int n) {
    int count = 0;
    int org = n;
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++) {
        int digit = s[i] - '0';
        if (digit != 0 && org % digit == 0) count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Count of digits that evenly divide " << n << " is " << evenlyDivides(n);
    return 0;
}
