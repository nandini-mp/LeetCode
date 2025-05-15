class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us(nums.begin(),nums.end());
        if (us.size()<nums.size())
            return true;
        return false;

    }
};