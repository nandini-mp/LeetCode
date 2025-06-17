class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        for (int i=0;i<32;i++)
        {
            result<<=1; //left shift result to make space for new bit
            result=result|(n&1); //extract last bit from n and add to result
            n>>=1; //shift n right to process next bit
        }
        return result;
    }
};