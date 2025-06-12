class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit=n&1;
        n>>=1;
        while (n!=0)
        {
            int lastBit=n&1; //if last bit of n is 1, lastBit=1;
            if (lastBit==bit)
                return false;
            bit=lastBit;
            n>>=1;
        }
        return true;
    }
};