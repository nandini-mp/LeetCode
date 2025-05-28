class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int start=-1,end=-1,i=0,j=0;
        while (i<nums.size() && j<nums.size())
        {
            while (i<nums.size() && nums[i]!=target)
            {
                i++;
                j++;
            }
            if (i==nums.size())
                return {-1,-1};
            start=i;
            j=i+1;
            while (j<nums.size() && nums[start]==nums[j])
                j++;  
            end=j-1;
            break;
        }
        return {start,end};
    }
};