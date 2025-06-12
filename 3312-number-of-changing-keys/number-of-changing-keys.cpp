class Solution {
public:
    int countKeyChanges(string s) {
        int num=0;
        for (int i=0;i<s.length()-1;i++)
        {
            if (tolower(s[i])==tolower(s[i+1]))
                continue;
            num++;
        }
        return num;
    }
};