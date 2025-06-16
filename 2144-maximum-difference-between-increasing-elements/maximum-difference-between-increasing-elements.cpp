class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minVal=nums[0],n=nums.size(),maxDiff=-1;
        for (int i=0;i<n;i++)
        {
            if (nums[i]>minVal)
                maxDiff=max(maxDiff,nums[i]-minVal);
            else
                minVal=nums[i];
        }
        return maxDiff;
    }
};