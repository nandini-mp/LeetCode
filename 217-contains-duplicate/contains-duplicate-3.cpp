class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us; //unordered set us in which we insert elements from nums if not in us yet
        for (int i=0;i<nums.size();i++)
        {
            if (us.count(nums[i])) //count returns 1 if in us, if nums[i] is in us, it means there's a duplicate
                return true;
            us.insert(nums[i]); //if not duplicate, insert into the set
        }
        return false;
    }
};
