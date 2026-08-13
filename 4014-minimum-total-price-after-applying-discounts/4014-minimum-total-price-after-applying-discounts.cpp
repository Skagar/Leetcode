class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        int n=prices.size();
        int m=discounts.size();
        int i=n-1;
        int j=m-1;
        double sum=0.0;
        while(i>=0 && j>=0)
        {
            double p=(double)prices[i];
            double d=(double)discounts[j];
            double fp=(p*(100.0-d))/100.0;
            sum+=fp;
            i--;
            j--;
        }
        while(i>=0)
        {
            sum+=(double)prices[i];
            i--;
        }
        return sum;
    }
};