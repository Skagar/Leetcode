class Solution {
private:
    int calfact(int n) {
        int prod = 1;
        while (n != 1) {
            prod = prod * n;
            n--;
        }
        return prod;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        int fact = calfact(n);
        map<int, int> fq;
        for (int i = 0; i < n; i++) {
            fq[nums[i]]++;
        }
        for (auto i : fq) {
            if (i.second > 1)
                fact = (fact / calfact(i.second));
        }
        vector<vector<int>> ans;
        ans.push_back(nums);
        int cnt = 1;
        while (cnt != fact) {
            next_permutation(nums.begin(), nums.end());
            ans.push_back(nums);
            cnt++;
        }
        return ans;
    }
};