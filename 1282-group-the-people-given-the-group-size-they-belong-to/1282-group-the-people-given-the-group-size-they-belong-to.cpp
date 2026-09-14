class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<pair<int, int>> p;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            p.push_back({groupSizes[i], i});
        }
        sort(p.begin(), p.end());
        for (int i = p.size() - 1; i >= 0; i--) {
            if (ans.empty()) {
                ans.push_back({p[i].second});
            } else {
                vector<int> temp = ans.back();
                if (temp.size() < p[i].first) {
                    ans[ans.size() - 1].push_back(p[i].second);
                } else {
                    ans.push_back({p[i].second});
                }
            }
        }
        return ans;
    }
};