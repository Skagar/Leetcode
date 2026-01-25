class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=nums.size()-1;i>=k-1;i--)
        {
            int maxi=nums[i];
        int mini=nums[i-k+1];
        ans=min(ans,(maxi-mini));
        }
       
       return ans;
       
    }
};