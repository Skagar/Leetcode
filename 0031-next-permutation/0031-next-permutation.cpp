class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
            }
        }
        if (ind == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        int minele = INT_MAX;
        int minind = -1;
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                if (nums[i] < minele) {
                    minele = nums[i];
                    minind = i;
                }
            }
        }
        if(minind!=-1)
        swap(nums[minind],nums[ind]);
        vector<int>temp;
        for(int i=ind+1;i<n;i++)
        {
            temp.push_back(nums[i]);
        }
        sort(temp.begin(),temp.end());
        int cnt=0;
        for(int i=ind+1;i<n;i++)
        {
           nums[i]=temp[cnt++];
        }
    }
};