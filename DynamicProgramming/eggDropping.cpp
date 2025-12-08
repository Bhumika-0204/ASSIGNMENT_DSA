#include <bits/stdc++.h>
using namespace std;

int main(){
    int eggs, floors;
    cin>>eggs>>floors;

    vector<vector<int>> dp(eggs+1, vector<int>(floors+1,0));

    for(int i=1;i<=eggs;i++){
        dp[i][0]=0;
        dp[i][1]=1;
    }
    for(int f=1;f<=floors;f++) dp[1][f]=f;

    for(int e=2;e<=eggs;e++){
        for(int f=2;f<=floors;f++){
            dp[e][f]=1e9;
            for(int k=1;k<=f;k++)
                dp[e][f]=min(dp[e][f],
                             1+max(dp[e-1][k-1], dp[e][f-k]));
        }
    }
    cout<<dp[eggs][floors];
}
