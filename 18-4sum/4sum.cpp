class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        long long t=target;
        sort(nums.begin(),nums.end());
        for (int i=0;i<n;i++)
        {
            if (i>0 && nums[i]==nums[i-1])
                continue;
            for (int j=i+1;j<n;j++)
            {
                if (j>i+1 && nums[j]==nums[j-1]) //not the first element, ie, 2 js are similar and this is the second j
                    continue;
                int k=j+1,l=n-1;
                while (k<l)
                {
                    long long sum=1LL*nums[i]+nums[j]+nums[k]+nums[l];
                    if (sum==t)
                    {
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++; l--;
                        while (k<l && nums[k]==nums[k-1]) k++;
                        while (k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if (sum<target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};