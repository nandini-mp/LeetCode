class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insert=0;
        for (int i=0;i<nums.size();i++)
            if (nums[i]!=0)
            {
                nums[insert]=nums[i];
                insert++;
            }
        for (int i=insert;i<nums.size();i++)
            nums[i]=0;
    }
};