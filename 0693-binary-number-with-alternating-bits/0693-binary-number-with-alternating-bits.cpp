class Solution {
public:
    bool hasAlternatingBits(int n) {
        stack<int> st;
        while (n != 0) {
            int ele = n % 2;
            if (st.empty()) {
                st.push(ele);
            } else {
                int topele = st.top();
                if (topele == ele)
                    return false;
                st.push(ele);
            }
            n = n / 2;
        }
        return true;
    }
};