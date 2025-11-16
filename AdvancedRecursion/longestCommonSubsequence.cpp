#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    vector<vector<int>> dp;

    int helper(int i,int j,string &text1,string &text2 ){
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + helper(i-1, j-1, text1, text2);
        }

        return dp[i][j] = max(helper(i-1, j, text1, text2),
                              helper(i, j-1, text1, text2));
    }

    int longestCommonSubsequence(string text1, string text2) {

        dp.assign(text1.size(), vector<int>(text2.size(), -1));

        int i = text1.size() - 1;
        int j = text2.size() - 1;

        return helper(i, j, text1, text2);
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    Solution obj;
    cout << obj.longestCommonSubsequence(s1, s2);
}
