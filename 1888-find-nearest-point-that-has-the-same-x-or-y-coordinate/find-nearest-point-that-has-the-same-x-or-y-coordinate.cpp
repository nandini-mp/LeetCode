class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int distance,index,minD=INT_MAX;
        for (int i=0;i<points.size();i++)
        {
            if (points[i][0]==x || points[i][1]==y)
            {
                distance=abs(x-points[i][0])+abs(y-points[i][1]);
                if (distance<minD)
                {
                    minD=distance;
                    index=i;
                }
            }
        }
        if (minD==INT_MAX) return -1;
        return index;
    }
};