#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int,int> m;
        stack <int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            while(s.size()>0 &&s.top()<=nums2[i]){
                s.pop();
            }
            if(s.empty()) {
                m[nums2[i]]=-1;

            }
            else m[nums2[i]]=s.top();
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> nums1={1,3,6,7};
    vector<int> nums2={1,22,33,7,0,44,6,7,3};

    vector<int> res=sol.nextGreaterElement(nums1, nums2);
    for(int i=0;i<res.size()-1;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}


