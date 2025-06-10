class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int left=0,maxFreq=0;
        long long currentSum=0;
        sort(nums.begin(),nums.end());
        for (int right=0;right<nums.size();right++)
        {
            currentSum+=nums[right];
            //the cost to make all elements in the window [left,right] equal to nums[right] is (window_size*nums[right])-current_sum_of_window_elements
            //while the cost exceeds k, shrink the window from the left (since nums is sorted)
            while ((long long)(right-left+1)*nums[right]-currentSum>k)
            {
                currentSum-=nums[left];
                left++;
            }
            //the current window [left,right] is valid, update maxFreq
            maxFreq=max(maxFreq,right-left+1);
        }
        return maxFreq;
    }
};