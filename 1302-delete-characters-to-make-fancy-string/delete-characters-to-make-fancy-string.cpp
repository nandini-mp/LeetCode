class Solution {
public:
    string makeFancyString(string s) {
        string res="";
        int n=s.length();
        int left=0;
        while (left<n)
        {
            char currentChar=s[left];
            int right=left;
            while (right<n && s[right]==currentChar)
                right++;
            int count=right-left;
            res+=string(min(2,count),currentChar);
            left=right;
        }
        return res;
    }
};