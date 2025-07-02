class Solution {
private:
    int rob1(vector<int>& nums)
    {
        int n=nums.size(),prev=nums[0],prev2=0;
        if (n==0) return 0;
        if (n==1) return prev;
        for (int i=1;i<n;i++)
        {
            int take=nums[i];
            if (i>1) take+=prev2;
            int notTake=prev;
            int curi=max(take,notTake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }

public:
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        if (nums.size()==1) return nums[0];
        for (int i=0;i<nums.size();i++)
        {
            if (i!=0) temp1.push_back(nums[i]);
            if (i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));   
    }
};