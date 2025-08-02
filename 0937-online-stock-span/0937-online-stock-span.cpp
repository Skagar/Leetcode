class StockSpanner {
    private:
    stack<pair<int,int>>st;
    int ind;
public:
    StockSpanner() {
        ind=-1;
    }
    
    int next(int price) {
        ind=ind+1;
        int ans;
        while(!st.empty() && (price >= st.top().second))
        {
            st.pop();
        }
        if(st.empty())
        {
            ans=ind+1;
        }
        else
        {
            ans=ind-st.top().first;
        }
        st.push({ind,price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */