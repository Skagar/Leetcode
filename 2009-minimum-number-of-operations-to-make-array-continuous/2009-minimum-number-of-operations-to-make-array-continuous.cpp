class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> st(begin(nums), end(nums));
        vector<int> temp(st.begin(), st.end());
        int result = INT_MAX;
        for (int i = 0; i < temp.size(); i++) {
            int L = temp[i];
            int R = L + n - 1;
            int j = upper_bound(temp.begin(), temp.end(), R) - temp.begin();
            int out = n - (j - i);
            result = min(result, out);
        }
        return result;
    }
};