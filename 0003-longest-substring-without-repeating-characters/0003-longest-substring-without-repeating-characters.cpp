class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.length(); r++) {
            char ch = s[r];

            if (mp.find(ch) != mp.end() && mp[ch] >= l) {
                l = mp[ch] + 1;
            }

            mp[ch] = r;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};