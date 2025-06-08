class Solution {
public:
    int numberOfPoints(vector<vector<int>>& v) {
        sort(v.begin(), v.end()); //lowest to highest start point
        int ans = 0, k = 0; //ans is total unique points so far, k furthest point
        for (auto &i : v) { //each car's rangle - [start,end]
            if (i[1] > k) { //means this interval extends past what's already covered
                ans += i[1] - max(i[0] - 1, k); //i[0]-1 because start is included, i[1] is the end point which is new (going past)
            }
            k = max(i[1], k); //update new
        }
        return ans;
    }
};