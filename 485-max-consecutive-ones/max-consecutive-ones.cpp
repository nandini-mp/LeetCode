class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,max=0;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]==0)
            {
                if (count>max)
                    max=count;
                count=0;
            }
            else
            {
                count++;
                if (count>max)
                    max=count;
            }
        }
        return max;
    }
};