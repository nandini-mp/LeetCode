class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> numFreq;
        for (int i=0;i<nums.size();i++)
            numFreq[nums[i]]++;
        for (auto& pair : numFreq)
            if (pair.second>floor(nums.size()/2))
                return pair.first;
        return -1;
    }
};