class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxCount=0;
        unordered_map<int,int> counts;
        for (int i=0;i<nums.size();i++)
            counts[nums[i]]++;
        for (auto& [num,freq]:counts)
            if (counts.count(num+1))
                maxCount=max(maxCount,freq+counts[num+1]);
        return maxCount;
    }
};

/*
for (const pair<int, int>& p : counts) {
    int num = p.first;
    int freq = p.second;
    ...
}
*/