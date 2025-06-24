class Solution {
public:
    void findCombinationSum(int index,int target,vector<int>& arr,vector<int>& ds, vector<vector<int>>& result)
    {
        if (target==0)
        {
            result.push_back(ds);
            return;
        }
        for (int i=index;i<arr.size();i++)
        {
            if (i>index && arr[i]==arr[i-1]) continue;
            if (arr[i]>target) break;
            ds.push_back(arr[i]);
            findCombinationSum(i+1,target-arr[i],arr,ds,result);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> ds;
        findCombinationSum(0,target,candidates,ds,result);
        return result;
    }
};