class Solution {
public:
    bool checkRecord(string s) {
        int a=0;
        for (int i=0;i<s.size();i++)
            if (s[i]=='A')
                a++;
        if (a<2 && s.find("LLL")==string::npos)
            return true;
        return false;
    }
};