class Solution {
public:
    int mySqrt(int x) {
        if (x<2) return x;
        int left=1,right=x,ans=0;
        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if ((long long)mid*mid<=x)
            {
                ans=mid; //store possible result
                left=mid+1; //try for a bigger one
            }
            else
                right=mid-1; //mid is too big
        }
        return ans;
    }
};