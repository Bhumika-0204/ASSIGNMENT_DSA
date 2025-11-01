#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char getMaxOccurringChar(string s) {
        sort(s.begin(), s.end());
        int maxFreq = 1, currFreq = 1;
        char maxChar = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) currFreq++;
            else {
                if (currFreq > maxFreq) {
                    maxFreq = currFreq;
                    maxChar = s[i - 1];
                }
                currFreq = 1;
            }
        }
        if (currFreq > maxFreq) {
            maxFreq = currFreq;
            maxChar = s[s.size() - 1];
        }
        return maxChar;
    }
};

int main() {
    string s;
    cout<<"Enter  string:";
    cin>>s;
    Solution obj;
    char ans = obj.getMaxOccurringChar(s);
    cout << "Max occurring character: " << ans << endl;
    return 0;
}
