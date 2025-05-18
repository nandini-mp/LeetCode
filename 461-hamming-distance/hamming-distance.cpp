class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorVal = x^y;
        return __builtin_popcount(xorVal);
    }
};