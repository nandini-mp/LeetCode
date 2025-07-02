class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),count=0,borderCount=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for (int i=0;i<m;i++)
        {
            if (grid[i][0]==1 && !visited[i][0])
            {
                visited[i][0]=1;
                borderCount++;
                q.push({i,0});
                while (!q.empty())
                {
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();
                    for (int i=0;i<4;i++)
                    {
                        int newRow=row+drow[i];
                        int newCol=col+dcol[i];
                        if (newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]==1 && !visited[newRow][newCol])
                        {
                            visited[newRow][newCol]=1;
                            borderCount++;
                            q.push({newRow,newCol});
                        }
                    }
                }
            }
            if (grid[i][n-1]==1 && !visited[i][n-1])
            {
                visited[i][n-1]=1;
                borderCount++;
                q.push({i,n-1});
                while (!q.empty())
                {
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();
                    for (int i=0;i<4;i++)
                    {
                        int newRow=row+drow[i];
                        int newCol=col+dcol[i];
                        if (newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]==1 && !visited[newRow][newCol])
                        {
                            visited[newRow][newCol]=1;
                            borderCount++;
                            q.push({newRow,newCol});
                        }
                    }
                }
            }
        }

        for (int i=0;i<n;i++)
        {
            if (grid[0][i]==1 && !visited[0][i])
            {
                visited[0][i]=1;
                borderCount++;
                q.push({0,i});
                while (!q.empty())
                {
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();
                    for (int i=0;i<4;i++)
                    {
                        int newRow=row+drow[i];
                        int newCol=col+dcol[i];
                        if (newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]==1 && !visited[newRow][newCol])
                        {
                            visited[newRow][newCol]=1;
                            borderCount++;
                            q.push({newRow,newCol});
                        }
                    }
                }
            }
            if (grid[m-1][i]==1 && !visited[m-1][i])
            {
                visited[m-1][i]=1;
                borderCount++;
                q.push({m-1,i});
                while (!q.empty())
                {
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();
                    for (int i=0;i<4;i++)
                    {
                        int newRow=row+drow[i];
                        int newCol=col+dcol[i];
                        if (newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]==1 && !visited[newRow][newCol])
                        {
                            visited[newRow][newCol]=1;
                            borderCount++;
                            q.push({newRow,newCol});
                        }
                    }
                }
            }
        }
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                if (grid[i][j]==1)
                    count++;
        return count-borderCount;
    }
};