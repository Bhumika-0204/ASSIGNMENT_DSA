#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> mp;

        // Step 1 → Count unmatched secret digits
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                bulls++;   // exact match
            else
                mp[secret[i]]++;  // count only unmatched digits
        }

        // Step 2 → Count cows (same digit but different position)
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] != guess[i]) {
                if (mp[guess[i]] > 0) {
                    cows++;
                    mp[guess[i]]--;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main() {
    string secret, guess;
    cout << "Enter secret string: ";
    cin >> secret;
    cout << "Enter guess string: ";
    cin >> guess;

    SolutionSTL sol;
    cout << "Hint = " << sol.getHint(secret, guess) << endl;

    return 0;
}
