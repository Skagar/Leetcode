class Solution {
public:
    long long splitArray(vector<int>& nums) {
        vector<int> indices;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1])
                indices.push_back(i - 1);
        }
        if (n < 2)
            return -1;
        else if (n == 2) 
            return abs(nums[0] - nums[1]);
        else if (indices.size() == 0) {
            long long prevsum = 0;
            for (int i = 1; i < n; i++) {
                if (nums[i - 1] != nums[i])
                    prevsum += nums[i-1];
                else
                    return -1;
            }
            return abs(prevsum - nums[n - 1]);
        }
        int ind = indices[0];
        bool flag = true;
        vector<pair<long long, long long>> sub;  
        for (int i = 0; i <= ind; i++) {
            flag = true; 
            long long sum = 0;
            int j = i + 2;  
            while (j < n) {
                if (nums[j] >= nums[j - 1]) {
                    flag = false;
                    break;
                } 
                sum += nums[j];
                j++;
            }
            
            if (flag == true) {
                long long leftSum = 0;
                for (int k = 0; k <= i; k++) {
                    leftSum += nums[k];
                }
                if (i + 1 < n) {
                    sum += nums[i + 1];
                }
                
                sub.push_back({leftSum, sum});
            }
        }
        if (sub.empty())
            return -1;
        
        vector<long long> diff; 
        for (int i = 0; i < sub.size(); i++) {
            diff.push_back(abs(sub[i].first - sub[i].second));
        }
        return *min_element(diff.begin(), diff.end());
    }
    
};