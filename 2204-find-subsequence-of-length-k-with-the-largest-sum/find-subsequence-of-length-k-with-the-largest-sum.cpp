class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> val_idx;
        for (int i = 0; i < nums.size(); i++)
            val_idx.push_back({nums[i], i});
        sort(val_idx.begin(), val_idx.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.first > b.first;
        });
        set<int> indices;
        for (int i = 0; i < k; i++)
            indices.insert(val_idx[i].second);
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
            if (indices.count(i))
                result.push_back(nums[i]);
        return result;
    }
};

/*
sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
    return a.first > b.first;
});
[] → capture list (empty here, means it captures nothing).
(const pair<int,int>& a, const pair<int,int>& b) → parameters.
{ return a.first > b.first; } → function body returning true if a should come before b.
*/