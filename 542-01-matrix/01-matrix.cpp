class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> distance(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
            {
                if (mat[i][j]==0)
                    q.push({{i,j},0});
            }
        while (!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            visited[row][col]=1;
            q.pop();
            if (mat[row][col]==1)
                distance[row][col]=t;
            else
                distance[row][col]=0;
            for (int i=0;i<4;i++)
            {
                int newRow=row+drow[i];
                int newCol=col+dcol[i];
                if (newRow>=0 && newRow<m && newCol>=0 && newCol<n)
                {
                    if (!visited[newRow][newCol])
                    {
                        visited[newRow][newCol]=1;
                        q.push({{newRow,newCol},t+1});
                    }
                }
            }
        }
        return distance;
    }
};