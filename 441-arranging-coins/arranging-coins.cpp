class Solution {
public:
    int arrangeCoins(int n) {
        int count=0,sum=n,i=1;
        while (sum>0)
        {
            count++;
            sum-=i;
            i++;
        }
        if (sum==0)
            return count;
        return count-1;
    }
};