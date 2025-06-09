class Solution {
public:
    int countAsterisks(string s) {
        int chars=0,full=0;
        for (char c:s)
        {
            if (c=='|' && full==0) full=1;
            else if (c=='|') full=0;
            else if (c=='*' && full==0) chars++;
        }
        return chars;
    }
};