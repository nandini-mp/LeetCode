class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> numbers;
        for (int i=0;i<nums.size();i++)
            numbers[nums[i]]++;
        int i;
        for (i=0;i<nums.size();i++)
        {
            if (numbers[nums[i]]==2)
                continue;
            return nums[i];
        }
        return nums[i];
    }
};