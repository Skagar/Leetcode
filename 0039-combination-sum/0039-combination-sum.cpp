class Solution {
private:
void findacombination(vector<int>&candidates, vector<int>&temp, vector<vector<int>>&ans,int target,int ind,int n)
{
    if(ind>=n)
    {
        if(target==0)
        {
            ans.push_back(temp);
        }
        return;
    }
    if(target==0)
    {
       ans.push_back(temp);
    return;
    }
    
    if(ind<n && target>=candidates[ind])
    {
        temp.push_back(candidates[ind]);
        findacombination(candidates,temp,ans,target-candidates[ind],ind,n);
        temp.pop_back();
    }
     if(ind + 1 < n && ind + 1 >= 0) {  // Check for both overflow and bounds
    findacombination(candidates, temp, ans, target, ind+1, n);
}
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        int n=candidates.size();
        findacombination(candidates,temp,ans,target,0,n);
      return ans;
    }
};