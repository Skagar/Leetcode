class Solution {
private:
    bool check(int n) {
        set<int> st;
        while (n != 0) {
            st.insert(n % 2);
            n = n / 2;
            if (st.size() == 2)
                return false;
        }
        if (st.size() == 2)
            return false;
        return true;
    }

public:
    int countMonobit(int n) {
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (check(i))
                cnt++;
        }
        return cnt;
    }
};