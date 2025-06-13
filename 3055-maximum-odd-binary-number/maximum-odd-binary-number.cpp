class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count=0;
        string res;
        for (int i=0;i<s.length();i++)
            if (s[i]=='1')
                count++;
        for (int i=0;i<count-1;i++)
            res+="1";
        for (int i=0;i<s.length()-count;i++)
            res+="0";
        res+="1";
        return res;
    }
};