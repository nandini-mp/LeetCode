class Solution {
public:
    int minAddToMakeValid(string s) {
        int openNeeded=0,moves=0;
        for (char ch:s)
        {
            if (ch=='(') openNeeded++;
            else if (ch==')')
            {
                if (openNeeded>0) openNeeded--;
                else moves++;
            }
        }
        if (openNeeded>0) moves+=openNeeded;
        return moves;
    }
};

//we can either have an extra closing parenthesis, a ) with no unmatched (, and an extra opening parenthesis, leftover ( after scanning, must insert ) for each
//openNeeded can represent the number of unmatched ( we have, and moves the insertions we've made so far