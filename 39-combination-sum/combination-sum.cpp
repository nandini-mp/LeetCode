class Solution {
public:
    void findCombinationSum(int index,int target,vector<int>& arr,vector<int>&ds,vector<vector<int>>& result)
    {
        if (index==arr.size())
        {
            if (target==0) result.push_back(ds);
            return;
        }
        if (arr[index]<=target)
        {
            ds.push_back(arr[index]);
            findCombinationSum(index,target-arr[index],arr,ds,result);
            ds.pop_back();
        }
        findCombinationSum(index+1,target,arr,ds,result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> result;
        findCombinationSum(0,target,candidates,ds,result);
        return result;
    }
};