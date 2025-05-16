class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i=0;i<nums.size();i++)
        {   
            int index=0;
            while (index<nums.size())
            {
                if (nums[i]+nums[index]==target && i!=index)
                {
                    res.push_back(i);
                    res.push_back(index);
                    return res;
                }
                index++;
            }
        }
        return res;
    }
};