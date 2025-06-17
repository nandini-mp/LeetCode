class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        if (s.length()<=1) return s;
        for (char ch:s)
            if (!st.empty() && abs(st.top()-ch)==32) //stack not empty and letters are UL
                st.pop();
            else st.push(ch);
        string result(st.size(),' ');
        for (int i=st.size()-1;i>=0;i--)
        {
            result[i]=st.top();
            st.pop();
        }
        return result;
    }
};