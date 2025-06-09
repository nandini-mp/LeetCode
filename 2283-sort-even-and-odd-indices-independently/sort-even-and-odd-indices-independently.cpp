class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even,odd;
        int n=nums.size();
        for (int i=0;i<n;i++)
            if (i%2==0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int>());
        int evenIndex=0,oddIndex=0;
        for (int i=0;i<n;i++)
            nums[i]=(i%2==0)?even[evenIndex++]:odd[oddIndex++];
        return nums;
    }
};