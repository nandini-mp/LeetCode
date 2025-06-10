class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums(n,start);
        int ans=0;
        for (int i=0;i<nums.size();i++)
        {
            nums[i]+=2*i;
            ans^=nums[i];
        }
        return ans;
            
        
    }
};