class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x=0,y=0;
        for (string move:commands)
            if (move=="UP") y--;
            else if (move=="DOWN") y++;
            else if (move=="RIGHT") x++;
            else x--;
        return y*n+x;
    }
};