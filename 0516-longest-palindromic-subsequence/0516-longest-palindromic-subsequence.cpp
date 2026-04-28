class Solution {
private:
    int calmaxlength(int ind1, int ind2, string& s, vector<vector<int>>& dp) {
        if (ind1 == ind2)
            return 1;
        if (ind1 > ind2)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (s[ind1] == s[ind2])
            return dp[ind1][ind2] =
                       (2 + calmaxlength(ind1 + 1, ind2 - 1, s, dp));
        else
            return dp[ind1][ind2] = max(calmaxlength(ind1 + 1, ind2, s, dp),
                                        calmaxlength(ind1, ind2 - 1, s, dp));
    }

public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return calmaxlength(0, n - 1, s, dp);
    }
};