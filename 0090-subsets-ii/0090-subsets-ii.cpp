;
#include <bits/stdc++.h> 
class Solution {
public:
void calsub(int ind,int n,vector<int>&nums,set<vector<int>>&ans,vector<int>&temp)
{
 if(ind==n)
 {
     ans.insert(temp);
     return;
 }
temp.push_back(nums[ind]);
calsub(ind+1,n,nums,ans,temp);
temp.pop_back();
calsub(ind+1,n,nums,ans,temp);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>ans;
    vector<int>temp;
    sort(nums.begin(),nums.end());
    calsub(0,nums.size(),nums,ans,temp);
    vector<vector<int>>final(ans.begin(),ans.end());
    return final;
    }
};