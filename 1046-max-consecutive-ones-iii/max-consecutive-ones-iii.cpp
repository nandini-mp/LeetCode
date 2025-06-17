class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,maxLen=0,zeroCount=0,n=nums.size();
        for (int right=0;right<n;right++) //we use a sliding window to keep track of a valid range [left,right] with at most k zeroes in it
        {
            if (nums[right]==0) //if the current number is a zero, we need to flip it so increment the count of 0s in the window
                zeroCount++; //zeroCount is the number of 0s in current window
            while (zeroCount>k) //if we've flipped more than k zeroes, then the window is invalid so we start shrinking it from the left
            {
                if (nums[left]==0) //if we remove a 0, we decrease zeroCount
                    zeroCount--;
                left++; //move left pointer forward to reduce window size
            }
            maxLen=max(maxLen,right-left+1); //now, the window [left,right] has at most k zeroes so update maxLen if this is the longest so far
        }
        return maxLen;
    }
};