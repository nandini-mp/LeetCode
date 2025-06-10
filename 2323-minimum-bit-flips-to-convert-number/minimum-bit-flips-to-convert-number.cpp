class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult=start^goal; //number with 1s where start and goal differ, so we count them
        int count=0;
        while (xorResult)
        {
            count+=xorResult&1; //if last bit is 1, we get a 1
            xorResult>>=1; //right shift so the last bit is gone
        }
        return count;
    }
};