class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        long long val = 3;
        if (num % val != 0)
            return ans;
        long long q = num / val;
        ans.push_back(q - 1);
        ans.push_back(q);
        ans.push_back(q + 1);
        return ans;
    }
};