class Solution {
public:
    int numberOfSteps(int num) {
        int steps=0;
        while (num)
        {
            num=(num&1)?num-1:num>>1; //num&1 checks if last bit is 1 (odd)
            steps++;
        }
        return steps;
    }
};