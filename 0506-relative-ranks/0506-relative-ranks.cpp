class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }
        int pos = 0;
        while (!pq.empty()) {
            pos++;
            int ind = pq.top().second;
            if (pos == 1)
                ans[ind] = "Gold Medal";
            else if (pos == 2)
                ans[ind] = "Silver Medal";
            else if (pos == 3)
                ans[ind] = "Bronze Medal";
            else {
                ans[ind] = to_string(pos);
            }
            pq.pop();
        }
        return ans;
    }
};