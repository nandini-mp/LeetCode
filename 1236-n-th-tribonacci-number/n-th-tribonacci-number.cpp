class Solution {
public:
    int tribonacci(int n) {
        if (n==1 || n==2) return 1;
        int a=0,b=1,c=1,d=0;
        for (int i=0;i<=n-3;i++)
        {
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return d;
    }
};