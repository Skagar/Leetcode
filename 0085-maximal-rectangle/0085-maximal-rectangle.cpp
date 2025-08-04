class Solution {
    private:
    int largestrecinhis(int *arr, int n)
    {
        stack<int>st;
        int area=INT_MIN;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                int ele=arr[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()? -1:st.top();
                area=max(area,((nse-pse-1)*ele));
            }
            st.push(i);
        }
         while(!st.empty())
            {
                int ele=arr[st.top()];
                st.pop();
                int nse=n;
                int pse= st.empty()? -1:st.top();
                area=max(area ,((nse-pse-1)*ele));
            }
            return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int *v=new int[m];
        for(int j=0;j<m;j++)
        {
         v[j]=matrix[0][j] -'0';
        }
        int area=largestrecinhis(v,m);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 int e=matrix[i][j] -'0';
                 if(e!=0)
                {
                    v[j]=((matrix[i][j] -'0')+v[j]);
                }
                 else
                 v[j]=0;
            }
            area=max(area,largestrecinhis(v,m));
        }
        return area;
    }
};