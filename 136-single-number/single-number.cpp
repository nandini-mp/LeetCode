class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i;
        for (i=0;i<nums.size();i++)
        {
            if (count(nums.begin(),nums.end(),nums[i])==2)
                continue;
            return nums[i];
        }
        return nums[i];
    }
};