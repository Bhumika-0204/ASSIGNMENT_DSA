#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeNonAlphabets(string s) {
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
                result += s[i];
            }
        }
        return result;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    Solution obj;
    string ans = obj.removeNonAlphabets(s);

    cout << "String after removing non-alphabetic characters: " << ans << endl;
    return 0;
}
