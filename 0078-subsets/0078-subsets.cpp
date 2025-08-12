class Solution {
    private:
    void generatesubsets(vector<vector<int>>&ans,vector<int>&temp,vector<int>& nums,int n,int &ind)
    {
       if(ind>=n) //Base Case
       {
        ans.push_back(temp);
        return;
       }
        temp.push_back(nums[ind]);
        ind++;
        generatesubsets(ans,temp,nums,n,ind);
        ind--;
        temp.pop_back();
        ind++;
        generatesubsets(ans,temp,nums,n,ind);
        ind--;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int>temp;
        int ind=0;
         generatesubsets(ans,temp,nums,n,ind);
         return ans;
    }
};