class Solution {
    private:
    bool iscontainzero(int val)
    {
        while(val!=0)
        {
            if(val%10==0)
            return true;
            val=val/10;
        }
        return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        int i=1;
        int j=n-1;
        long long sum=0;
        while(i<=j)
        {
            if(iscontainzero(i)==true)
            {
                i++;
                continue;
            }
            if(iscontainzero(j)==true )
            {
                j--;
                continue;
            }
               sum=sum+i+j;
               if(sum==n)
               {
                ans.push_back(i);
                ans.push_back(j);
                break;
               }
               else if(sum>n)
               {
                j--;
                sum=0;
               }
               else
               {
                i++;
                sum=0;
               }
        }
        return ans;
    }
};