class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0,i=0,n=nums.size();
        while (i<n)
        {
            int start=nums[i];
            count++; //start a new group
            while (i<n && nums[i]-start<=k)
                i++;
        }
        return count;
    }
};