class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> ele;
        map<long long, long long> fq;
        map<long long, vector<long long>> idx;
        long long ans = LLONG_MAX;
        for (long long i = 0; i < n; i++) {
            fq[nums[i]]++;
            idx[nums[i]].push_back(i);
        }
        for (auto i : fq) {
            if (i.second >= 3)
                ele.push_back(i.first);
        }
        if (ele.empty())
            return -1;
        for (long long i = 0; i < ele.size(); i++) {
            vector<long long> temp = idx[ele[i]];
            for (long long j = 1; j < temp.size(); j++) {
                if (j + 1 < temp.size())
                    ans = min(ans, (abs(temp[j] - temp[j - 1]) +
                                    abs(temp[j] - temp[j + 1]) +
                                    abs(temp[j + 1] - temp[j - 1])));
            }
        }
        return (int)ans;
    }
};