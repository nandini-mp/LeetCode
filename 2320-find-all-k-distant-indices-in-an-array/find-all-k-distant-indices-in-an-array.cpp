class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<bool> mark(n,false);
        for (int i=0;i<n;i++)
        {
            if (nums[i]==key)
            {
                int start=max(0,i-k); //if i-k is less than 0 ( we need k distance both to left and right hence start can be i-k or if negative 0)
                int end=min(n-1,i+k); //end can be i+k or if it exceeds length, then n-1
                for (int j=start;j<=end;j++)
                    mark[j]=true;
            }
        }
        vector<int> result;
        for (int i=0;i<n;i++)
            if (mark[i]) result.push_back(i);
        return result;
    }
};