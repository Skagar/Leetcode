class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        int range = st.size() - 3;
        if (range < 0)
            return (*max_element(nums.begin(), nums.end()));
        else {
            for (auto i : st) {
                if (cnt == range)
                    return i;
                else
                    cnt++;
            }
        }
        return  -1;
    }
};