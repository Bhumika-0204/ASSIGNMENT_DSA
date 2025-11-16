#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int helper(vector<int>&arr,int start,int end){
        int prev1=0,prev2=0;
        for(int i=start;i<end;i++){
            int temp=max(prev1,prev2+arr[i]);
            prev2=prev1;
            prev1=temp;
        }
        return prev1;
    }
    int rob(vector<int>&arr){
        int n=arr.size();
        if(n==1) return arr[0];
        return max(helper(arr,0,n-2),helper(arr,0,n-1));
    }
};
int main() {
    int n;
    cout << "Enter number of houses: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter money in each house: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    solution obj;
    cout << "Maximum money that can be robbed: " << obj.rob(arr) << endl;

    return 0;
}