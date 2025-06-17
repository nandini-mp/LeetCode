class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for (char ch:s)
        {
            if (!isdigit(ch))
                st.push(ch);
            else if (st.empty() && isdigit(ch))
                continue;
            else
                st.pop();
        }
        string res(st.size(),' ');
        for (int i=st.size()-1;i>=0;i--)
        {
            res[i]=st.top();
            st.pop();
        }
        return res;
    }
};