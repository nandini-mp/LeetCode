class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int sum=0,pos=0;
        for (int i=0;i<nums.size();i++)
            if (nums[i]>0)
            {
                pos=1;
                st.insert(nums[i]);
            }
        if (pos==0)
        {
            sum=INT_MIN;
            for (int i=0;i<nums.size();i++)
                sum=max(sum,nums[i]);
            return sum;
        }
        for (int num:st)
            sum+=num;
        return sum;
    }
};