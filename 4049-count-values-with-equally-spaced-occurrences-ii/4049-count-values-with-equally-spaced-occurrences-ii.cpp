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
            if (i.second.size() >= 3) {
                vector<long long> temp = i.second;
                bool flag = true;
                long long diff = temp[1] - temp[0];
                for (long long j = 1; j < temp.size(); j = j + 1) {
                    if ((temp[j] - temp[j - 1]) != diff) {
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                    cnt++;
            }
        }
        return cnt;
    }
};