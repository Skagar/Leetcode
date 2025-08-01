class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0)
                ans.push_back(asteroids[i]);
            else {
                while (!ans.empty() && ans.back() > 0 &&
                       abs(asteroids[i]) > ans.back()) {
                    ans.pop_back();
                }
                if (!ans.empty() && ans.back() > 0 &&
                    abs(asteroids[i]) == ans.back()) {
                    ans.pop_back();
                } else if (ans.empty() || ans.back() < 0)
                    ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};