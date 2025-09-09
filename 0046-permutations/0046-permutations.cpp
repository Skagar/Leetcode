class Solution {
    private:
    void calpermute(vector<int>&nums, vector<vector<int>>&ans,int n,int ind)
    {
     if(ind>=n)
     {
        ans.push_back(nums);
        return;
     }
     for(int i=ind;i<n;i++)
     {
        swap(nums[ind],nums[i]);
        calpermute(nums,ans,n,ind+1);
        swap(nums[ind],nums[i]);
     }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>>ans;
         int n=nums.size();
         int ind=0;
         calpermute(nums,ans,n,ind);
         return ans;
    }
};