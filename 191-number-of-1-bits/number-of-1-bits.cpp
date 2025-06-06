class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while (n)
        {
            n=n&(n-1); //n-1 flips the lowest set bit from 1 to 0, also flips all bits to the right of it from 0 to 1, by AND-ing with n, we clear the lowest set bit because the flipped bit in n-1 is now 0 where n was 1 so AND makes that bit 0, and bits to the right become 0 after AND since n had zeroes there, finally n ends up having no set bits
            count++;
        }
        return count;
    }
};