class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int len=min(word1.length(),word2.length());
        for (int i=0;i<len;i++)
        {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        if (word1.length()>len)
            for (int i=len;i<word1.length();i++)
                result.push_back(word1[i]);
        if (word2.length()>len)
            for (int i=len;i<word2.length();i++)
                result.push_back(word2[i]);
        return result;
    }
};