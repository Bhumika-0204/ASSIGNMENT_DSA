#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={2,4,22,4,7,1,3};
    stack<int> s;
    vector<int> ans(arr.size(),0);
    for(int i=arr.size()-1;i>=0;i--){
        while(s.size()>0 && s.top()<=arr[i]){
            s.pop();

        }
        if(s.empty() )  ans[i]=-1;
        else ans[i]=s.top();
        s.push(arr[i]);


    }
    for(int val:ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
