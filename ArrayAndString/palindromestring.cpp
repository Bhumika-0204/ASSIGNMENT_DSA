#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Move left pointer to next alphanumeric
            while (left < right && !isalnum(s[left])) left++;
            // Move right pointer to previous alphanumeric
            while (left < right && !isalnum(s[right])) right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    Solution obj;
    bool result = obj.isPalindrome(s);

    if (result)
        cout << "The string is a valid palindrome." << endl;
    else
        cout << "The string is not a palindrome." << endl;

    return 0;
}
