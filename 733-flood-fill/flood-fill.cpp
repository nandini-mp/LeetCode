class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size();
        if (image[sr][sc]==color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int givenColour=image[sr][sc];
        image[sr][sc]=color;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while (!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for (int i=0;i<4;i++)
            {
                int newRow=row+drow[i];
                int newCol=col+dcol[i];
                if (newRow>=0 && newRow<m && newCol>=0 && newCol<n && image[newRow][newCol]==givenColour)
                {
                    image[newRow][newCol]=color;
                    q.push({newRow,newCol});
                }
            }
        }
        return image;
    }
};