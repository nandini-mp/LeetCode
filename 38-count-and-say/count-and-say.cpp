class Solution {
public:
    string nextTerm(string s)
    {
        string res="";
        int i=0,n=s.length();
        while (i<n)
        {
            char ch=s[i];
            int count=0;
            while (i<n && s[i]==ch)
            {
                i++; count++;
            }
            res+=to_string(count);
            res.push_back(ch);
        }
        return res;
    }

    string countAndSay(int n) {
        string s="1";
        for (int k=1;k<n;k++)
            s=nextTerm(s);
        return s;
    }
};