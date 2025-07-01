class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),countFresh=0;
        queue<pair<pair<int,int>,int>> q; //coordinates as a pair and time
        vector<vector<int>> visited(n, vector<int>(m,0));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                if (grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else
                    visited[i][j]=0;
                if (grid[i][j]==1) countFresh++;
            }
                
        int count=0,timeMax=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while (!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            timeMax=max(timeMax,t);
            q.pop();
            for (int i=0;i<4;i++)
            {
                int newRow=row+drow[i];
                int newCol=col+dcol[i];
                if (newRow>=0 && newRow<n && newCol>=0 && newCol<m && visited[newRow][newCol]!=2 && grid[newRow][newCol]==1)
                {
                    q.push({{newRow,newCol},t+1});
                    visited[newRow][newCol]=2;
                    count++;
                }
            }
        }
        if (count!=countFresh) return -1;        
        return timeMax;
    }
};