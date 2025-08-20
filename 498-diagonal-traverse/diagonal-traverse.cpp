class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int> result;
        unordered_map<int,vector<int>> mpp;

        for (int row=0;row<m;row++)
            for (int col=0;col<n;col++)
                mpp[row+col].push_back(mat[row][col]); //elements belong to the same diagonal
        for (int s=0;s<=m+n-2;s++)
        {
            if (s%2==0)
                reverse(mpp[s].begin(),mpp[s].end());
            for (int val:mpp[s])
                result.push_back(val);
        }
        return result;
    }
};