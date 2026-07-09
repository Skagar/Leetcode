class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        /*  int m = queries.size();
          vector<pair<int, int>> comp;
          vector<bool> ans(m, false);
          int i = 1;
          while (i < n) {
              int mini = i - 1;
              while (i < n && (nums[i] - nums[i - 1]) <= maxDiff) {
                  i++;
              }
              comp.push_back({mini, i - 1});
              i++;
          }
          if (!comp.empty() && comp.back().second != n - 1)
              comp.push_back({n - 1, n - 1});
          for (int j = 0; j < m; j++) {
              int l = queries[j][0];
              int r = queries[j][1];
              if (l == r) {
                  ans[j] = true;
              } else {
                  for (int k = 0; k < comp.size(); k++) {
                      int lol = comp[k].first;
                      int upl = comp[k].second;
                      if (lol != upl && l >= lol && r <= upl && l <= upl &&
                          r >= lol) {
                          ans[j] = true;
                          break;
                      } else if (l >= lol && l <= upl && r > upl)
                          break;
                  }
              }
          }
          return ans;*/
        int m = queries.size();
        vector<int> comp(n);
        vector<bool> ans(m);
        int cnt = 0;
        comp[0] = cnt;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                cnt++;
            comp[i] = cnt;
        }
        for (int i = 0; i < m; i++) {
            ans[i] = comp[queries[i][0]] == comp[queries[i][1]];
        }
        return ans;
    }
};