class Solution {
public:
    int bitwiseComplement(int n)
     {
        if(n<0||n>pow(10,90))
        {
        return 0;
        exit(0);
        }
        if(n==0)
        {
            return 1;
            exit(0);
        }
         int arr[30];
        int sum=0;
        int i=0,c=0;
        while(n!=0)
        {
            arr[i]=(n%2);
            n=n/2;
            i++;
        }
       for(int j=i-1;j>(i-1)/2;j--)
        {
            int t=arr[j];
            arr[j]=arr[i-1-j];
            arr[i-1-j]=t;
        }
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]==1)
                arr[j]=0;
                else
                arr[j]=1;
            sum=sum+ (arr[j])*pow(2,c);
            c++;
        }

        return sum;
    }
};