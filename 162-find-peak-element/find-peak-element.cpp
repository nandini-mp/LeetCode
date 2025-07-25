class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int peakIndex=n-1;
        int index=n-2,max=nums[n-1];
        while (index>=0)
        {
            if (nums[index]>max)
            {
                max=nums[index];
                peakIndex=index;
            }
            else
                return peakIndex;
            index--;
        }
        return peakIndex;
    }
};