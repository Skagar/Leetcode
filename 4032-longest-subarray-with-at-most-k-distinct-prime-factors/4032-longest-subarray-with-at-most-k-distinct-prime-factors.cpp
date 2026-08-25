class Solution {
private:
    void markprime(vector<int>& prime) {
        prime[0] = 0;
        prime[1] = 0;
        for (int i = 2; i < prime.size(); i++) {
            if (prime[i] == 1) {
                for (int j = 2 * i; j < prime.size(); j = j + i) {
                    prime[j] = 0;
                }
            }
        }
    }
    void calfactor(int num, int ind, vector<int>& prime,
                   vector<vector<int>>& str, map<int, int>& mp) {
        for (int div = 2; div * div <= num; div++) {
            if (num % div == 0) {
                if (prime[div] == 1) {
                    str[ind].push_back(div);
                    mp[div]++;
                }
                while (num % div == 0) {
                    num /= div;
                }
            }
        }
        if (num > 1) {
            str[ind].push_back(num);
            mp[num]++;
        }
    }

public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> prime(maxi + 1, 1);
        markprime(prime);
        vector<vector<int>> str(n);
        int l = 0;
        int r = 0;
        int maxlen = INT_MIN;
        map<int, int> mp;
        while (r < n) {
            calfactor(nums[r], r, prime, str, mp);
            while (l <= r && mp.size() > k) {
                vector<int> temp = str[l];
                for (auto i : temp) {
                    mp[i]--;
                    if (mp[i] == 0)
                        mp.erase(i);
                }
                l++;
            }
            if (l > r) {
                r++;
                continue;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        if (maxlen != INT_MIN)
            return maxlen;
        return 0;
    }
};