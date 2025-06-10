class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        for (int i=0;i<s.length();i++)
        {
            unordered_set<char> seen;
            for (int j=i;j<s.length();j++)
            {
                if (seen.count(s[j]))
                    break;
                seen.insert(s[j]);
                if (j-i+1>maxLen)
                    maxLen=j-i+1;
            }
        } 
        return maxLen;
    }
};