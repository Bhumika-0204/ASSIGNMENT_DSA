#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int n = str.length();
    int spaces = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == ' ')
            spaces++;
    }

    cout << "The number of words are " << spaces + 1;
    return 0;
}
