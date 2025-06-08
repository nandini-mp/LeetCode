class Solution {
public:
    int minimumMoves(string s) {
        int moves=0;
        for (int i=0;i<s.length();i++)
        {
            if (s[i]=='O') continue;
            s[i]='O';
            if (i+1<s.length()) s[i+1]='O';
            if (i+2<s.length()) s[i+2]='O';
            moves++;
            i+=2;
        }
        return moves;
    }
};