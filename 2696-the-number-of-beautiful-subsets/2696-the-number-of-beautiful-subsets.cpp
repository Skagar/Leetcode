class Solution {
    private:
    int countsubsets(vector<int>& nums,vector<int>&temp,int ind,int k,int n)
    {
        if(ind>=n)
        {
            sort(temp.begin(),temp.end());
            int s=temp.size();
            if(s==0)
            return 0;
            if(s==1)
            return 1;
            for(int i=0;i<s;i++)
            {
               for(int j=i+1;j<s;j++)
               {
                 int diff=abs(temp[j]-temp[i]);
                if(diff==k)
                return 0;
               }
            }
            return 1;
        }
        temp.push_back(nums[ind]);
        int l=countsubsets(nums,temp,ind+1,k,n);
        temp.pop_back();
        int r=countsubsets(nums,temp,ind+1,k,n);
        return l+r;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        int n=nums.size();
        int ans=countsubsets(nums,temp,0,k,n);
        return ans;
    }
};