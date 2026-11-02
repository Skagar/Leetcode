class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int midele=nums[n/2];
        long long ans=0LL;
        for(int i=0;i<n;i++)
        {
            ans+=1LL*(abs(nums[i]-midele));
        }
        return ans;
    }
};