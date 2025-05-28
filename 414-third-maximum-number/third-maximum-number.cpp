class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max=INT_MIN,secondMax=INT_MIN,thirdMax=INT_MIN,foundThird=0;
        for (int i=0;i<nums.size();i++)
            if (nums[i]>=max)
                max=nums[i];
        for (int i=0;i<nums.size();i++)
            if (nums[i]>=secondMax && nums[i]!=max)
                secondMax=nums[i];
        for (int i=0;i<nums.size();i++)
            if (nums[i]>=thirdMax && nums[i]!=max && nums[i]!=secondMax)
            {
                thirdMax=nums[i];
                foundThird=1;
            }
                
        if (thirdMax==INT_MIN && foundThird==0)
            return max;
        return thirdMax;
    }
};