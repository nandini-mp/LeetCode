class Solution {
public:
    void genParenthesis(vector<string>& res,int open,int close,string str)
    {
        if (open == 0 && close == 0)
            res.push_back(str);
        if (open>0)
            genParenthesis(res,open-1,close,str+"(");
        if (close>open)
            genParenthesis(res,open,close-1,str+")");
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        genParenthesis(result,n,n,"");
        return result;
    }
};