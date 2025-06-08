class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int> rowCount(m,0),colCount(n,0);
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
            {
                if (mat[i][j])
                {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        int specialPositions=0;
        for (int i=0;i<m;i++)
        {
            if (rowCount[i]==1)
            {
                for (int j=0;j<n;j++)
                    if (mat[i][j] && colCount[j]==1)
                        specialPositions++;
            }
        }
        return specialPositions;
    }
};