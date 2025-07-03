class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while (s.length()<k)
        {
            string s1=s;
            for (int i=0;i<s.length();i++)
            {
                if (s[i]=='z')
                    s1[i]='a';
                else
                    s1[i]=s[i]+1;
            }   
            s+=s1;
        }
        return s[k-1];
    }
};