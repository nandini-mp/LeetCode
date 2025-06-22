class Solution {
public:
    int climbStairs(int n) {
        if (n<=2) return n;
        int a=1,b=1,c;
        for (int i=0;i<=n-2;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};