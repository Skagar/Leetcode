class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        long long n = nums.size();
        long long cnt = 0;
        map<long long, vector<long long>> mp;
        for (long long i = 0; i < n; i++) {
            mp[(long long)nums[i]].push_back(i);
        }
        for (auto i : mp) {
            if (i.second.size() == 3) {
                vector<long long> temp = i.second;
                long long j = 1;
                if ((temp[j] - temp[j - 1]) == (temp[j + 1] - temp[j]))
                    cnt++;
            }
        }
        return cnt;
    }
};