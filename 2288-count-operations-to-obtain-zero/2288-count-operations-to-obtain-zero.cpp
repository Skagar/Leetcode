class Solution {
public:
    int countOperations(int num1, int num2) {
        long long c = 0;
        while (num1 != 0 && num2 != 0) {
            c++;
            if (num1 >= num2)
                num1 = num1 - num2;
            else
                num2 = num2 - num1;
        }
        return c;
    }
};