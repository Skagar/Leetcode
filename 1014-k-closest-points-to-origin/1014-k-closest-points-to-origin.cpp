class Solution {
    int distCalc(int x, int y) {
        long long sum = (x * x) + (y * y);
        return (int)sum;
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxh;
        vector<vector<int>> ans;
        vector<int> temp;
        int r = points.size();
        int c = points[0].size();
        for (int i = 0; i < r; i++) {
            if (k > 0) {
                maxh.push({distCalc(points[i][0], points[i][1]),
                           {points[i][0], points[i][1]}});
                k--;
            } else {
                if (maxh.top().first > distCalc(points[i][0], points[i][1])) {
                    maxh.pop();
                    maxh.push({distCalc(points[i][0], points[i][1]),
                               {points[i][0], points[i][1]}});
                    ;
                }
            }
        }
        while (!maxh.empty()) {
            temp.push_back(maxh.top().second.first);
            temp.push_back(maxh.top().second.second);
            maxh.pop();
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};