class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxh;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            if (k > 0) {
                int diff = abs(arr[i] - x);
                maxh.push({diff, arr[i]});
                k--;
            } else {
                int diff = abs(arr[i] - x);
                if (diff < maxh.top().first) {
                    maxh.pop();
                    maxh.push({diff, arr[i]});
                } else if (diff == maxh.top().first) {
                    if (maxh.top().second > arr[i]) {
                        maxh.pop();
                        maxh.push({diff, arr[i]});
                    }
                }
            }
        }
        while (!maxh.empty()) {
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};