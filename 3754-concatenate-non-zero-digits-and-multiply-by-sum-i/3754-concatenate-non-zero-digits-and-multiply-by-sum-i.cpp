class Solution {
public:
    long long sumAndMultiply(int n) {
        int num = 0;
        int sum=0;
        while (n != 0) {
            int rem = n % 10;
            sum+=rem;
            if (rem != 0) {
                num = (num * 10) + rem;
            }
            n=n/10;
        }
        int x=0;
        while(num!=0)
        {
            x=(x*10)+(num%10);
            num=num/10;
        }
        long long prod=1LL*(long long)x*(long long)sum;
        return prod;
    }
};