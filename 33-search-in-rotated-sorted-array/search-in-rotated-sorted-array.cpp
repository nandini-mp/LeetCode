class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int mid,low=0,high=n-1;
        while (low<=high)
        {
            mid=(low+high)/2;
            if (nums[mid]==target)
                return mid;
            else if (nums[low]<=nums[mid]) //left half sorted
                if (nums[low]<=target && target<=nums[mid]) //target in left half
                    high=mid-1;
                else //target in right half
                    low=mid+1;
            else //right half sorted
                if (nums[mid]<=target && target<=nums[high]) //target in right half
                    low=mid+1;
                else //target in left half
                    high=mid-1;
        }
        return -1;
    }
};