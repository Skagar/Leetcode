;
#include <bits/stdc++.h> 
class Solution {
public:
//Brute force Approach
/*void calsub(int ind,int n,vector<int>&nums,set<vector<int>>&ans,vector<int>&temp) 
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
}*/



void calsub(int ind,int n,vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp) 
{
     ans.push_back(temp);
for(int i=ind;i<n;i++)
{
    if((i!=ind)&& (nums[i]==nums[i-1]))
    continue;
    temp.push_back(nums[i]);
    calsub(i+1,n,nums,ans,temp);
    temp.pop_back();
}
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //Brute forec approach of using set and then transferring it into vector of vector
    /*set<vector<int>>ans; 
    vector<int>temp;
    sort(nums.begin(),nums.end());
    calsub(0,nums.size(),nums,ans,temp);
    vector<vector<int>>final(ans.begin(),ans.end());
    return final;*/
    

    //Better approach
     vector<int>temp;
    sort(nums.begin(),nums.end());
     vector<vector<int>>ans;
    calsub(0,nums.size(),nums,ans,temp);
    return ans;
    }
};