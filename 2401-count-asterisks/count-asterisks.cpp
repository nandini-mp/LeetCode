class Solution {
public:
    int countAsterisks(string s) {
        int chars=0;
        stack<int> st;
        for (char c:s)
        {
            if (c=='|' && st.empty()) st.push(c);
            else if (c=='|') st.pop();
            else if (c=='*' && st.empty()) chars++;
        }
        return chars;
    }
};