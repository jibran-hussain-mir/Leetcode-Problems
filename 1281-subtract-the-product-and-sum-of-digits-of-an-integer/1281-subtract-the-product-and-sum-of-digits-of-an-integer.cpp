class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0;
        int product=1;
        while(n)
        {
            int digits=n%10;
            sum=sum+digits;
            product=product*digits;
            n=n/10;
        }
        return product-sum;
    }
};