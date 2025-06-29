class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // Precompute powers of 2
        vector<int> pow2(n, 1);
        for(int i = 1; i < n; i++) {
            pow2[i] = (pow2[i-1] * 2) % mod;
        }
        int left = 0, right = n -1;
        int ans = 0;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + pow2[right-left]) % mod;
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};

/*first sort the array so the smallest element in a subsequence will always come on the left side and the largest on the right. Then we use two pointers left and right, left points to the smallest candidate and right to the largest. If nums[left]+nums[right]<=target, all subsets formed by elements between left and right are valud. The number of subsequences with nums[left] as minimum and nums[right] maximum is 2^(right-left) since we can either pick or not pick each element between left+1 and right (nums[left] is always included because it's the minimum) */