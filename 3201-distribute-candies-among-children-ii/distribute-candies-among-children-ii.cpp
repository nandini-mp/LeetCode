class Solution {
public:
    long long combinations(int n,int k)
    {
        if (k<0 || k>n) return 0;
        long long res=1;
        for (int i=1;i<=k;i++)
        {
            res*=(n-i+1);
            res/=i;
        }
        return res;
    }

    long long distributeCandies(int n, int limit) {
        long long total=combinations(n+2,2); //total unrestricted
        total-=combinations(n-(limit+1)+2,2); //a>limit
        total-=combinations(n-(limit+1)+2,2); //b>limit
        total-=combinations(n-(limit+1)+2,2); //c>limit
        total+=combinations(n-2*(limit+1)+2,2); //add a and b > limit
        total+=combinations(n-2*(limit+1)+2,2); //add b and c > limit
        total+=combinations(n-2*(limit+1)+2,2); // add a and c > limit
        total-=combinations(n-3*(limit+1)+2,2); //subtract a,b,c>limit
        return total;
    }
};