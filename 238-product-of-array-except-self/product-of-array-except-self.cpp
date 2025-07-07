class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        //res[i]=product of all elements to the left of i*product of all elements to the right of i
        int left=1;
        for (int i=0;i<n;i++)
        {
            res[i]=left; //set current left to res[i]
            left*=nums[i]; //multiply with nums[i] for the next nums element pdt
        }
        int right=1;
        for (int i=n-1;i>=0;i--)
        {
            res[i]*=right;
            right*=nums[i];
        }
        return res;
    }
};