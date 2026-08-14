class Solution {
public:
    int maximumLengthSubstring(string s) {
        int len = s.length();
        int maxlen = INT_MIN;
        map<char, int> mp;
        int l = 0;
        int r = 0;
        while (l <= r && r < len) {
            mp[s[r]]++;
            while (l <= r && mp[s[r]] >= 3) {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        if (maxlen == INT_MIN)
            return -1;
        return maxlen;
    }
};