class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1,n=nums.size();
        for (int i=n-2;i>=0;i--) //to find breakpoint
            if (nums[i]<nums[i+1])
            {
                index=i;
                break;
            }
        if (index==-1) //no breakpoint, at last permutation
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for (int i=n-1;i>index;i--)
            if (nums[i]>nums[index]) //nge
            {
                int temp=nums[i];
                nums[i]=nums[index];
                nums[index]=temp;
                break;
            }
        reverse(nums.begin()+index+1,nums.end()); //right half is already sorted in decreasing order, we want the smallest hence reverse
        return;
    }
};