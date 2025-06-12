class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int max=INT_MIN;
        for (int i=0;i<nums.size()-1;i++)
            if (abs(nums[i+1]-nums[i])>max)
                max=abs(nums[i+1]-nums[i]);
        if (abs(nums[0]-nums[nums.size()-1])>max)
            max=abs(nums[0]-nums[nums.size()-1]);
        return max;
    }
};