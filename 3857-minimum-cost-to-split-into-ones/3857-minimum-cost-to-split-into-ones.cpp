class Solution {
public:
    int minCost(int n) {
        stack<int> st;
        st.push(n);
        int cost = 0;
        if(n==1)
        return 0;
        while (!st.empty()) {
            int val = st.top();
            st.pop();
            int a = floor((double)val / (double)2);
            int b = ceil((double)val / (double)2);
            if (a != 1)
                st.push(a);
            if (b != 1)
                st.push(b);
            cost += (a * b);
        }
        return cost;
    }
};