class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> numbers;
        for (int num:nums)
            numbers.insert(num);
        int i=0;
        for (int num:numbers)
            nums[i++]=num;
        nums.resize(i);
        return i;
    }
};