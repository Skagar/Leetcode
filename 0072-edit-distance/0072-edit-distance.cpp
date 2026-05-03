class Solution {
    int calminoperations(int i, int j, string& word1, string& word2,
                         vector<vector<int>>& dp) {
        if (i == 0)
            return j;
        if (j == 0)
            return i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i - 1] == word2[j - 1])
            return dp[i][j] =
                       0 + calminoperations(i - 1, j - 1, word1, word2, dp);
        return dp[i][j] =
                   1 + min(calminoperations(i - 1, j - 1, word1, word2, dp),
                           min(calminoperations(i, j - 1, word1, word2, dp),
                               calminoperations(i - 1, j, word1, word2, dp)));
    }

public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if (len1 == 0)
            return len2;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        // Memoization
        //  return calminoperations(len1, len2, word1, word2, dp);

        for (int j = 0; j <= len2; j++) {
            dp[0][j] = j;
        }
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 0 + dp[i - 1][j - 1];
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1],
                                       min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[len1][len2];
    }
};