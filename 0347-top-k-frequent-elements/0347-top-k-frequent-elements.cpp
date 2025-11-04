class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto i : mp) {
                pq.push({i.second, i.first});
        }
        while (!pq.empty()) {
            if (k <= 0)
                break;
            else {
                ans.push_back(pq.top().second);
                pq.pop();
                k--;
            }
        }
        return ans;
    }
};