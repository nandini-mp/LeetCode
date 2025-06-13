class Solution {
public:
    bool canFormPairs(vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i++; // skip the next element to avoid reusing
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        /*we want to form p non-overlapping pairs such that the maximum absolute difference among all pairs is as small as possible. First, sort the array, so that similar values are close to each other, making it easier to pair with minimal differences. Binary search ie for each d, check if we can form at least p disjoint pairs where each pair has a difference <=d. Traverse the sorted array, greedily pair adjacent elements if their difference is <=d, skip the next element to prevent overlap*/
        sort(nums.begin(), nums.end());

        int low = 0, high = nums.back() - nums.front();
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canFormPairs(nums, p, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    /*Why Binary Search? Because we are trying to minimize the max diff between paired elements. Suppose you guess a max alllowed difference d. You can check if it's possible to form p non-overlapping pairs such that each pair has a difference ≤ d. If it's possible, maybe there's a smaller d that still works → search left. If not possible, you need a bigger d → search right.*/
};