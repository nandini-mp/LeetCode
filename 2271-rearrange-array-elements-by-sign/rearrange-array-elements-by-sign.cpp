class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg,numsCopy;
        int index=0;
        for (int i=0;i<nums.size();i++)
            if (nums[i]>0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        for (int i=0;i<nums.size()/2;i++)
        {
            numsCopy.push_back(pos[index]);
            numsCopy.push_back(neg[index]);
            index++;
        }
        return numsCopy;
    }
};