class Solution {
public:
    int minimumCost(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minh;
        int cost = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            minh.push({nums[i], i});
        }
        int cnt = 0;
        while (!minh.empty()) {
            if (cnt >= 2)
                break;
            int val = minh.top().first;
            minh.pop();
            cost = cost + val;
            cnt++;
        }
        return cost;
    }
};