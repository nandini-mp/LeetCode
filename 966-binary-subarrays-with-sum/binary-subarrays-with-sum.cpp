class Solution {
public:
    int lessThanGoal(vector<int>& nums,int goal)
    {
        if (goal<0) return 0;
        int l=0,r=0,sum=0,count=0,n=nums.size();
        while (r<n)
        {
            sum+=nums[r];
            while (sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return lessThanGoal(nums,goal)-lessThanGoal(nums,goal-1);
    }
};