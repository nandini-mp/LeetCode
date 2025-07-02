class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(),prev=nums[0],prev2=0;
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
};