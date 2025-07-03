class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& visited,int drow[],int dcol[])
    {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=1;
        while (!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for (int i=0;i<4;i++)
            {
                int newRow=row+drow[i];
                int newCol=col+dcol[i];
                if (newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]=='1' && !visited[newRow][newCol])
                {
                    q.push({newRow,newCol});
                    visited[newRow][newCol]=1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands=0,m=grid.size(),n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
            {
                if (grid[i][j]=='1' && !visited[i][j])
                {
                    islands++;
                    bfs(grid,i,j,visited,drow,dcol);
                }
            }
        return islands;
    }
};