class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> mp;
        int n = fruits.size();
        int l = 0;
        int r = 0;
        int ans = INT_MIN;
        while (r < n) {
            if (mp.size() <= 2) {
                mp[fruits[r]]++;
                if (mp.size() <= 2)
                    ans = max(ans, r - l + 1);
                r++;
            } else {
                while (mp.size() > 2) {
                    if (mp[fruits[l]] != 0) {
                        mp[fruits[l]]--;
                        if (mp[fruits[l]] == 0)
                            mp.erase(fruits[l]);
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};