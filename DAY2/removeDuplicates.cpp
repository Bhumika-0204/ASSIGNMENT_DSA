#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string s) {
    int index = 0;
    for (int i = 0; i < s.size(); i++) {
        int j;
        for (j = 0; j < i; j++)
            if (s[i] == s[j])
                break;
        if (j == i)
            s[index++] = s[i];
    }
    s.resize(index);
    return s;
}

int main() {
    string s;
    cout << "Enter a string:";
    getline(cin,s);
    cout << "String after removing duplicates: " << removeDuplicate(s);
    return 0;
}
