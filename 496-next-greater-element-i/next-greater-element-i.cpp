class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i=0;i<nums1.size();i++)
        {
            int j=0,found=0;
            while (j<nums2.size() && nums2[j]!=nums1[i])
                j++;
            if (j==nums2.size())
            {
                ans.push_back(-1);
                continue;
            }
            int index=j;
            while (j<nums2.size())
            {
                if (nums2[j]>nums2[index])
                {
                    ans.push_back(nums2[j]);
                    found=1;
                    j++;
                    break;
                }
                j++;
            }
            if (j==nums2.size() && found==0)
            {
                ans.push_back(-1);
                continue;
            }  
        }
        return ans;
    }
};