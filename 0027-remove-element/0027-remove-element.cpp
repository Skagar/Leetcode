class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ans;
        int n = nums.size();
        // BRUTE FORCE APPROACH
        /*for(int i=0;i<n;i++)
        {
            if(nums[i]!=val)
            ans.push_back(nums[i]);
        }
        int k=ans.size();
        for(int i=0;i<ans.size();i++)
        {
            nums[i]=ans[i];
    }
        return k;*/
        // optimal APPROACH
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right) {
            if(nums[left] == val) {
                // Swap with element from end and reduce array size
                nums[left] = nums[right];
                right--;
            } else {
                left++;
            }
        }
        return right + 1;
    }
};