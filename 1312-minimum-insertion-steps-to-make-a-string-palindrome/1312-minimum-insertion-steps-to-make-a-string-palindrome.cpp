class Solution {
    int calmaxlength(int ind1, int ind2, string& s, vector<vector<int>>& dp) {
        if (ind1 == ind2)
            return 1;
        if (ind1 > ind2)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (s[ind1] == s[ind2])
            return dp[ind1][ind2] = 2 + calmaxlength(ind1 + 1, ind2 - 1, s, dp);
        else
            return dp[ind1][ind2] = max(calmaxlength(ind1 + 1, ind2, s, dp),
                                        calmaxlength(ind1, ind2 - 1, s, dp));
    }

public:
    int minInsertions(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, -1));
        int lps = calmaxlength(0, len - 1, s, dp);
        return len - lps;
    }
};