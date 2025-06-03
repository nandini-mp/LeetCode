class Solution {
public:
    void swapIfGreater(vector<int>& a, vector<int>& b, int i, int j) {
        if (a[i] > b[j]) {
            swap(a[i], b[j]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int totalLen = m + n;
        int gap = (totalLen / 2) + (totalLen % 2);

        while (gap > 0) {
            int left = 0, right = gap;

            while (right < totalLen) {
                // Both pointers in nums1
                if (left < m && right < m) {
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                }
                // left in nums1, right in nums2
                else if (left < m && right >= m) {
                    if (nums1[left] > nums2[right - m]) {
                        swap(nums1[left], nums2[right - m]);
                    }
                }
                // both in nums2
                else {
                    if (nums2[left - m] > nums2[right - m]) {
                        swap(nums2[left - m], nums2[right - m]);
                    }
                }
                left++;
                right++;
            }

            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }

        // Copy sorted nums2 into nums1
        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }
    }
};