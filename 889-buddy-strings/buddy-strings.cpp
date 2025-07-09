class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length()!=goal.length()) return false;
        if (s==goal) //say ab and ab, if we have a duplicate character like aba, yes, we can swap once and still have the same string but ab won't work, so here, we're checking for duplicates
        {
            unordered_set<char> seen;
            for (char ch:s)
            {
                if (seen.count(ch)) return true;
                seen.insert(ch);
            }
            return false;   
        }
        int count=0,index=0;
        char sch1,sch2,gch1,gch2;
        while (index!=s.length())
        {
            if (s[index]!=goal[index] && count==0)
            {
                count++;
                sch1=s[index];
                gch1=goal[index];
            }
            else if (s[index]!=goal[index] && count==1)
            {
                count++;
                sch2=s[index];
                gch2=goal[index];
            }
            else if (s[index]!=goal[index])
                return false;
            index++;
        }
        if (count==2 && sch1==gch2 && sch2==gch1) return true;
        return false;
    }
};