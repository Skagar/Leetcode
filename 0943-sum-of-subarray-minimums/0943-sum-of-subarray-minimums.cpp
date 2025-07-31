class Solution {
    private:
    vector<int> findnse(vector<int>&arr)
    {
        int n=arr.size();
        stack<int>st;
        vector<int> ans;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty())
                ans.push_back(n);
            else
                ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    vector<int> findpse(vector<int>&arr)
    {
        int n=arr.size();
        stack<int>st;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[i]<arr[st.top()])  
            {
                st.pop();
            }
            if(st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
    
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse=findnse(arr);
        vector<int>pse=findpse(arr);
        long long mod = 1e9+7;
        long long total = 0;  
        int n = arr.size();
        
        for(int i=0;i<n;i++)
        {
            long long left = i - pse[i];     
            long long right = nse[i] - i;     
            long long contribution = (left * right % mod * arr[i]) % mod;
            total = (total + contribution) % mod;
        }
        
        return (int)total;
    }
};