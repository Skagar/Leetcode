class Solution {
    bool checkpalin(string& s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string& s, int& n, int& k, int i, int j,
              vector<vector<int>>& dp) {
        if (i >= n || j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (checkpalin(s, i, j)) {
            int take = 1 + solve(s, n, k, j + 1, j + k, dp);
            int grow = solve(s, n, k, i, j + 1, dp);
            int skip = solve(s, n, k, i + 1, j + 1, dp);
            return dp[i][j] = max(take, max(grow, skip));
        }
        int grow = solve(s, n, k, i, j + 1, dp);
        int skip = solve(s, n, k, i + 1, j + 1, dp);
        return dp[i][j] = max(grow, skip);
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        /*int cnt = 0;
         Greedy failed because it is not optimal to take starting position as
         fixed eg. abbaa greedily ans=1(abba) but best ans=2 aa and bb for
          k=2;
         int i = 0;
          while (i < n) {
              bool flag = false;
              int j = i + 1;
              string str = "";
              str += s[i];
              while (j <= n) {
                  if (str.length() >= k) {
                      if (checkpalin(str)) {
                          cout<<str<<" ";
                          flag = true;
                          cnt++;
                          i = j;
                          break;
                      } else
                          str += s[j++];
                  } else
                      str += s[j++];
              }
              if (flag == false)
                  i++;
          }
          return cnt;*/
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        if (k == 1)
            return n;
        return solve(s, n, k, 0, k - 1, dp);
    }
};