class Solution {
public:
    int digitSum(int num)
    {
        int sum=0;
        while (num!=0)
        {
            int digit=num%10;
            sum+=digit;
            num/=10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        for (int i=0;i<nums.size();i++)
            nums[i]=digitSum(nums[i]);
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};