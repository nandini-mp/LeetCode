class Solution {
public:
    void solve(int i,vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
            if (i==nums.size())
            {
                result.push_back(current);
                return;
            }
            current.push_back(nums[i]); //include nums[i]
            solve(i+1,nums,current,result);
            current.pop_back(); //exclude nums[i]
            solve(i+1,nums,current,result);
        }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        solve(0,nums,current,result);
        return result;
    }
};