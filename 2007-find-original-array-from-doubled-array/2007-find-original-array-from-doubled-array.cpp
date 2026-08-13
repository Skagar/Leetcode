class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        long long n = changed.size();
        if (n % 2 != 0)
            return {};
        map<long long, long long> mp;
        vector<int> ans;
        sort(changed.begin(), changed.end());
        for (long long i = 0; i < n; i++) {
            mp[changed[i]]++;
        }
        for (long long i = 0; i < n; i++) {
            long long ele = changed[i];
            if (mp[ele] != 0) {
                long long db = ele * 2 * 1LL;
                if (mp.find(db) != mp.end() && mp[db] > 0) {
                    ans.push_back((int)ele);
                    mp[ele]--;
                    mp[db]--;
                } else
                    return {};
            }
        }
        return ans;
    }
};