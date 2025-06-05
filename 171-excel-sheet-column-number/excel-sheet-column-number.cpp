class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0;
        for (char c:columnTitle)
            res=res*26+(c-'A'+1); //add 1 since Excel is 1-indexed, not 0
        return res;
    }
};