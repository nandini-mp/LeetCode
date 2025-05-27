class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1=points[0][0];
        int x2=points[1][0];
        int x3=points[2][0];
        int y1=points[0][1];
        int y2=points[1][1];
        int y3=points[2][1];
        return ((y2-y1)*(x3-x1)!=(y3-y1)*(x2-x1)); //non-collinearity
        //if slopes are equal taking P1P2 and P1P3, collinear, using slope eqn
    }
};