class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length()!=t.length())
            return false;
        unordered_map<char,char> mapST,mapTS;
        for (int i=0;i<s.length();i++)
        {
            char c1=s[i],c2=t[i];
            if (mapST.count(c1)) //we encountered c1 in S before, mapped to smthg already
            {
                if (mapST[c1]!=c2) //if it's not mapped to c2, means different
                                    return false;
            }
            else
                mapST[c1]=c2; //if letter not yet mapped
            if (mapTS.count(c2))
            {
                if (mapTS[c2]!=c1)
                    return false;
            }
            else
                mapTS[c2]=c1;
        }
        return true;
    }
};