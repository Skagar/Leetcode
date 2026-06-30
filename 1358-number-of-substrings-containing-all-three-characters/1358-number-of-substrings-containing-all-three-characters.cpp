class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        int l = 0;
        int r = 0;
        map<char, int> mp;
        int cnt = 0;
        while (l <= r && r < len) {
            mp[s[r]]++;
            while (!mp.empty() && mp.size() == 3) {
                cnt += (len - r);
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return cnt;
    }
};