class Solution {
    int calmaxlength(int ind1, int ind2, string& text1, string& text2,
                     vector<vector<int>>& dp) {
        if (ind1 == 0 || ind2 == 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        int tk = 0;
        int ntk = 0;
        if (text1[ind1 - 1] == text2[ind2 - 1])
            tk = 1 + calmaxlength(ind1 - 1, ind2 - 1, text1, text2,dp);
        else
            ntk = 0 + max(calmaxlength(ind1 - 1, ind2, text1, text2,dp),
                          calmaxlength(ind1, ind2 - 1, text1, text2,dp));
        return dp[ind1][ind2] = max(tk, ntk);
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1,
                               vector<int>(text2.size() + 1, -1));
        calmaxlength(text1.size(), text2.size(), text1, text2, dp);
        return dp[text1.size()][text2.size()];
    }
};