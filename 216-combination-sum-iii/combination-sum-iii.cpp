class Solution {
public:
    void findCombinations(int index,int target,vector<int>& arr,vector<int>& ds,vector<vector<int>>& result,int k)
    {
        if (target==0 && ds.size()==k)
        {
            result.push_back(ds);
            return;
        }
        for (int i=index;i<arr.size();i++)
        {
            if (i>index && arr[i]==arr[i-1]) continue;
            if (arr[i]>target) break;
            ds.push_back(arr[i]);
            findCombinations(i+1,target-arr[i],arr,ds,result,k);
            ds.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr={1,2,3,4,5,6,7,8,9};
        vector<int> ds;
        vector<vector<int>> result;
        findCombinations(0,n,arr,ds,result,k);
        return result;
    }
};