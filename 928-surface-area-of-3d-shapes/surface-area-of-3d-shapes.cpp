class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n=grid.size(),area=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                int v=grid[i][j];
                if (v>0)
                {
                    area+=v*6;
                    area-=(v-1)*2; //internal faces in the stack, say there are 2 cubes stacked, then 2 faces are lost
                    if (i>0)
                        area-=2*min(v,grid[i-1][j]); //top neighbour
                    if (j>0)
                        area-=2*min(v,grid[i][j-1]); //left neighbour
                    //if grid[i][j] and grid[x][y] are neighbours, they hide faces between them, say 3 and 4 in Example 1, they hide min(3,4)=3 faces between them
                }
            }
        }
        return area;
    }
};