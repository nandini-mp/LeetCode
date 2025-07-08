class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1,b=-1,c=-1,count=0,n=s.length();
        for (int i=0;i<n;i++)
        {
            if (s[i]=='a') a=i;
            else if (s[i]=='b') b=i;
            else if (s[i]=='c') c=i;
            if (a!=-1 && b!=-1 && c!=-1)
                count+=(1+min(a,min(b,c)));
        }
        return count;
    }
};