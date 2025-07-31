class Solution {
private:
    vector<int> findnse(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }
            if (st.empty())
                ans.push_back(n);
            else
                ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> findnge(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                st.pop();
            }
            if (st.empty())
                ans.push_back(n);
            else
                ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> findpse(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                st.pop();
            }
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
    vector<int> findpge(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                st.pop();
            }
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse = findnse(nums);
        vector<int> pse = findpse(nums);
        vector<int> nge = findnge(nums);
        vector<int> pge = findpge(nums);
        long long mintotal = 0;
        long long maxtotal = 0;
        int mod = (int)(1e9 + 7);
        for (int i = 0; i < n; i++) {
            long long leftmin = i - pse[i];
            long long rightmin = nse[i] - i;
            long long mincontri = (leftmin * rightmin * nums[i]);
            mintotal += mincontri;

            long long leftmax = i - pge[i];
            long long rightmax = nge[i] - i;
            long long maxcontri = (leftmax * rightmax * nums[i]);
            maxtotal += maxcontri;
        }
        return (maxtotal - mintotal);
    }
};