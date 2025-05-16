class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=count(nums.begin(),nums.end(),0);
        int white=count(nums.begin(),nums.end(),1);
        int blue=count(nums.begin(),nums.end(),2);
        for (int i=0;i<red;i++)
            nums[i]=0;
        for (int i=red;i<red+white;i++)
            nums[i]=1;
        for (int i=red+white;i<red+white+blue;i++)
            nums[i]=2;
    }
};