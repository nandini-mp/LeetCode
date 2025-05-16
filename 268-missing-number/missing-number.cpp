class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sumActual=n*(n+1)/2;
        int sumMissing=accumulate(nums.begin(),nums.end(),0);
        return sumActual-sumMissing;
    }
};