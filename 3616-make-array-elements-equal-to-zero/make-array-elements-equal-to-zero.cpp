class Solution {
public:
    bool simulate(vector<int>nums,int curr,int dir)
    {
        int n=nums.size();
        while (curr>=0 && curr<n) //in range
        {
            if (nums[curr]==0)
                curr+=dir; //move in curr dir by incr or decr curr
            else
            {
                nums[curr]--;
                dir=-dir;
                curr+=dir;
            }
        }
        for (int val:nums)
            if (val!=0) return false;
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int n=nums.size(),count=0;
        for (int i=0;i<n;i++)
        {
            if (nums[i]==0) //curr pos
            {
                if (simulate(nums,i,-1)) count++; //going left and got all 0s
                if (simulate(nums,i,1)) count++; //going right and got all 0s
            }
        }
        return count;
    }
};