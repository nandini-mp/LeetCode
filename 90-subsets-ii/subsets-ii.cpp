class Solution {
public:
    void subsetHelper(int index,vector<int>& nums,vector<int>& ds,vector<vector<int>>& result)
    {
        result.push_back(ds);
        for (int i=index;i<nums.size();i++)
        {
            if (i>index && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            subsetHelper(i+1,nums,ds,result);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        subsetHelper(0,nums,ds,result);
        return result;
    }
};