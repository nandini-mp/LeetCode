class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=0;
        long long count=0;
        while (right<n)
        {
            if (nums[right]==0)
            {
                left=right; //starting of zero block;
                while (right<n && nums[right]==0)
                    right++;
                long long len = right-left;
                count += (len*(len+1))/2; //formula for subarrays in block
            }
            else
                right++;
        }
        return count;
    }
};


/*
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0,streak=0;
        for (int num:nums)
        {
            if (num==0)
            {
                streak++; //extend the zero streak
                count+=streak;
            }
            else
                streak = 0; //reset streak
        }
        return count;
    }
};
*/