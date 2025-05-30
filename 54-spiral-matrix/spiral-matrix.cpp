class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int count=0,m=matrix.size(),n=matrix[0].size(),top=0,left=0,topCovered=0,leftCovered=0;
        vector<int> res;
        while (count!=m*n)
        {
            while (left<n-leftCovered && count<m*n)
            {
                res.push_back(matrix[top][left]);
                count++;
                left++;
            }
            left--;
            top++;
            while (top<m-topCovered && count<m*n)
            {
                res.push_back(matrix[top][left]);
                count++;
                top++;
            }
            top--;
            left--;
            while (left>=leftCovered && count<m*n)
            {
                res.push_back(matrix[top][left]);
                count++;
                left--;
            }
            left++;
            top--;
            leftCovered++;
            while (top>=topCovered+1 && count<m*n)
            {
                res.push_back(matrix[top][left]);
                count++;
                top--;
            }
            top++;
            left++;
            topCovered++;
        }
        return res;
    }
};