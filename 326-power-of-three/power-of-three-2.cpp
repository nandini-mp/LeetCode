class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<=0)
            return false;
        while (n!=0)
        {
            if (n==1 || n==3)
                return true;
            if (n%3!=0)
                return false;
            n/=3;
        }
        return true;
    }
};
