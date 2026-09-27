class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> mp(101, 0);
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        while (true) {
            bool done = true;
            for (int i = 1; i <= 100; i++) {
                if (mp[i] != 0) {
                    done = false;
                    ans.push_back(i);
                    mp[i]--;
                }
            }
            if (done == true)
                break;
        }
        return ans;
    }
};