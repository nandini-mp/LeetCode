class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closestNum;
        for (int i=0;i<nums.size();i++)
            if (abs(nums[i])<abs(closestNum))
                closestNum=nums[i];
            else if (abs(nums[i])==abs(closestNum))
                closestNum=nums[i]>closestNum?nums[i]:closestNum;
        return closestNum;
    }
};