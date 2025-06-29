class Solution {
public:
    int jump(vector<int>& nums)
    {
        int jumps=0,left=0,right=0,n=nums.size();
        while (right<n-1)
        {
            int farthest=0;
            for (int i=left;i<=right;i++)
                farthest=max(farthest,i+nums[i]);
            left=right+1;
            right=farthest;
            jumps++;
        }
        return jumps;
    }



/*    
    int jumpCount(int index,int jumps,vector<int>& nums)
    {
        int n=nums.size(),mini=INT_MAX;
        if (index>=n-1) return jumps;
        for (int i=1;i<=nums[index];i++) mini=min(mini,jumpCount(index+i,jumps+1,nums));
        return mini;
    }

    int jump(vector<int>& nums)
    {
        return jumpCount(0,0,nums);
    } */
};