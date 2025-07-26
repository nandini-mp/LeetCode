class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        using P=pair<int,pair<int,int>>;
        priority_queue<P,vector<P>,greater<P>> q;
        int m=heights.size(),n=heights[0].size();
        q.push({0,{0,0}});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        while (!q.empty())
        {
            int effort=q.top().first;
            int row=q.top().second.first;
            int col=q.top().second.second;
            q.pop();
            if (row==m-1 && col==n-1) return effort;
            if (effort>dist[row][col]) continue; //like the case {7,3} and {3,3} (dist,node), we need only {3,3} since shorter distance
            for (int i=0;i<4;i++)
            {
                int newRow=row+drow[i];
                int newCol=col+dcol[i];
                if (newRow>=0 && newRow<m && newCol>=0 && newCol<n)
                {
                    int wtDiff=abs(heights[newRow][newCol]-heights[row][col]);
                    int newEffort=max(effort,wtDiff);
                    if (newEffort<dist[newRow][newCol])
                    {
                        dist[newRow][newCol]=newEffort;
                        q.push({newEffort,{newRow,newCol}});
                    }
                }
            }
        }
        return 0;
    }
};