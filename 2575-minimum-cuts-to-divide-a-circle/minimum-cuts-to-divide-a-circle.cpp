class Solution {
public:
    int numberOfCuts(int n) {
        if (n%2==0) return n/2;
        if (n==1) return 0;
        return n;
    }
};