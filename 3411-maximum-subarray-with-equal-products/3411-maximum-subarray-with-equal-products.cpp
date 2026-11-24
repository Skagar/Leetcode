using ll = long long;
class Solution {
public:
    int maxLength(vector<int>& nums) {
        ll n = nums.size();
        ll maxlen = LLONG_MIN;
        for (ll i = 0; i < n; i++) {
            ll prod = 1LL * nums[i];
            ll g = 1LL * nums[i];
            ll l = 1LL * nums[i];
            for (ll j = i; j < n; j++) {
                if ((i == j) && (nums[i] == (nums[i] * nums[i]))) {
                    if (1 > maxlen) {
                        maxlen = 1;
                    }
                } else if (i != j) {
                    if (prod > 25200)
                        break;
                    prod = prod * nums[j];
                    g = gcd(g, nums[j]);
                    l = lcm(l, nums[j]);
                    if (prod == (g * l)) {
                        if ((j - i + 1) > maxlen) {
                            maxlen = j - i + 1;
                        }
                    }
                }
            }
        }
        return maxlen;
    }
};