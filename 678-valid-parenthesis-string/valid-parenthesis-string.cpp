class Solution {
public:
    bool checkValidString(string s) {
        int minC=0,maxC=0;
        for (int i=0;i<s.length();i++)
        {
            if (s[i]=='(')
            {
                minC++;
                maxC++;
            }
            else if (s[i]==')')
            {
                minC=max(0,minC-1);
                maxC--;
                if (maxC<0) return false;
            }
            else
            {
                minC=max(0,minC-1);
                maxC++;
            }
        }
        return minC==0;
    }
};