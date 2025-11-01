#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    void countFrequency(string s) {
        map<char, int> freq;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        cout << "Character frequencies:\n";
        for (auto it : freq) {
            cout << it.first << " : " << it.second << endl;
        }
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    Solution obj;
    obj.countFrequency(s);

    return 0;
}
