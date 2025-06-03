class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int depth=0;
        for (char c : s)
            if (c=='(')
            {
                if (depth>0)
                    result+=c; //only add if not the outermost (when we encounter the outermost, depth will be 0)
                depth++;
            }
            else
            {
                depth--;
                if (depth>0)
                    result+=c; //only add if still inside
            }
        return result;
    }
};