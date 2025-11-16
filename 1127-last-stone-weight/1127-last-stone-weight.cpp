class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            maxh.push(stones[i]);
        }
        while (maxh.size() > 1) {
            int y = maxh.top();
            maxh.pop();
            int x = maxh.top();
            maxh.pop();
            if (x != y)
                maxh.push(y - x);
        }
        if (!maxh.empty())
            return maxh.top();
        return 0;
    }
};